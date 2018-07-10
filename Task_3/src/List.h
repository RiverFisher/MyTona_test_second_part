#ifndef MYTONATEST_LIST_H
#define MYTONATEST_LIST_H


typedef struct {void *p; void *pEnd;} Iterator;
typedef struct {void *p; void *pEnd;} MutableIterator;

template <typename T>
class List {
    struct ListItem {
        ListItem * Next;
        T Data;
        explicit ListItem(const T& init) : Data(init) {}
    };

    struct ListHeader {
        int  size;
        int  refCount;
        ListItem * pFront;
        ListItem * pTail;

        ListHeader() : size(0), refCount(1), pFront(0), pTail(0) {}

        ListItem * root() const {
            return (ListItem *)(void *)&pFront;
        }
    } * m_header;

    void copyBeforeWrite() {
        if (m_header->refCount == 1) return;
        List<T> list;
        for (ListItem * p = m_header->pFront; p != 0; p = p->Next) {
            auto item = new ListItem(p->Data);
            item->Next = 0;
            if (m_header->pTail != 0) m_header->pTail->Next = item;
            m_header->pTail = item;
            if (m_header->pFront == 0) m_header->pFront = item;
            m_header->size++;
        }
        ListHeader * t = m_header;
        m_header = list.m_header;
        list.m_header = t;
    }

    void release() {
        if (--m_header->refCount == 0) {
            ListItem * p = m_header->pFront;
            while (p != 0) {
                ListItem * p2 = p;
                p = p->Next;
                delete p2;
            }
            delete m_header;
        }
    }

public:
    List() : m_header(new ListHeader) {}

    List(const List<T>& list) : m_header(list.m_header) {
        m_header->refCount++;
    }

    List<T>& operator = (const List<T>& list) {
        release();
        m_header = list.m_header;
        m_header->refCount++;
    }

    void clear() {
        List<T> empty;
        ListHeader * t = m_header;
        m_header = empty.m_header;
        empty.m_header = t;
    }

    inline bool isEmpty() const {
        return m_header->pFront == 0;
    }

    int getsize() const {
        return m_header->size;
    }

    void pushFront(const T& item) {
        auto li = new ListItem(item);
        copyBeforeWrite();
        li->Next = m_header->pFront;
        m_header->pFront = li;
        if (m_header->pTail == 0) m_header->pTail = li;
        m_header->size++;
    }

    void pushBack(const T& item) {
        auto li = new ListItem(item);
        copyBeforeWrite();
        li->Next = 0;
        if (m_header->pTail != 0) m_header->pTail->Next = li;
        m_header->pTail = li;
        if (m_header->pFront == 0) m_header->pFront = li;
        m_header->size++;
    }

    void append(const T& item) {
        pushBack(item);
    }

    void popFront() {
        ListItem * front = m_header->pFront;
        m_header->pFront = front->Next;
        if (m_header->pTail == front) m_header->pTail = 0;
        delete front;
        m_header->size --;
    }

    const T& front() const {
        return m_header->pFront->Data;
    }

    const T& back() const {
        return m_header->pTail->Data;
    }

    void revert() {
        if (m_header->size <= 1) return;
        copyBeforeWrite();
        m_header->pTail = m_header->pFront;
        ListItem * i = m_header->pFront;
        ListItem * prev = 0;
        ListItem * t;
        while (i != 0) {
            t = i->Next;
            i->Next = prev;
            prev = i;
            i = t;
        }
        m_header->pFront = prev;
    }

    explicit operator Iterator() const {
        Iterator it {};
        it.p = (void *)m_header->root();
        it.pEnd = (void *)m_header->pTail;
        return it;
    }

    void iterate(Iterator& it) const {
        it.p = (void *)m_header->root();
        it.pEnd = (void *)m_header->pTail;
    }

    bool hasNext(const Iterator& it) const {
        return ((ListItem *)it.p)->Next != 0;
    }

    bool next(Iterator& it) const {
        if (it.p == nullptr || it.p == it.pEnd) return false;
        it.p = ((ListItem *)it.p)->Next;
        return true;
    }

    const T& operator[](const Iterator& it) const {
        ListItem * current  = ((ListItem *)it.p)->Next;
        return current->Data;
    }

    /*explicit operator MutableIterator() {
        MutableIterator it {};
        copyBeforeWrite();
        it.p = (void *)m_header->root();
        it.pEnd = (void *)m_header->pTail;
        return it;
    }

    void iterate(MutableIterator& it) {
        copyBeforeWrite();
        it.p = (void *)m_header->root();
        it.pEnd = (void *)m_header->pTail;
    }

    bool hasNext(const MutableIterator& it) const {
        return ((ListItem *)it.p)->Next != 0;
    }

    bool next(MutableIterator& it) const {
        if (it.p == nullptr || it.p == it.pEnd) return false;
        it.p = ((ListItem *)it.p)->Next;
        return true;
    }

    T& operator[](const MutableIterator& it) const {
        ListItem * current  = ((ListItem *)it.p)->Next;
        return current->Data;
    }

    void insert(const MutableIterator& place, const T& item) {
        auto it = new ListItem(item);
        auto p = (ListItem *)place.p;
        it->Next = p->Next;
        p->Next = it;
        m_header->size++;
        if (m_header->pTail == p) m_header->pTail = it;
    }

    void erase(const MutableIterator& place) {
        auto p = (ListItem *)place.p;
        ListItem * removed = p->Next;
        p->Next = removed->Next;
        if (removed == m_header->pTail) m_header->pTail = p;
        delete removed;
        m_header->size--;
    }*/

    bool remove(const T& item) {
        copyBeforeWrite();
        bool removed = false;
        ListItem * p = m_header->root();
        while (p->Next != 0) {
            ListItem * current = p->Next;
            if (current->Data == item) {
                p->Next = current->Next;
                if (current == m_header->pFront)
                    m_header->pFront = current->Next;
                delete current;
                m_header->size--;
                removed = true;
            }
            else p = p->Next;
        }
        m_header->pTail = p;
        return removed;
    }

    bool contains(const T& item) const {
        ListItem * p = m_header->pFront;
        while (p) {
            if (p->Data == item) return true;
            p = p->Next;
        }
        return false;
    }

    int replace(const T& item, const T& newvalue) {
        int count = 0;
        copyBeforeWrite();
        ListItem * p = m_header->pFront;
        while (p) {
            if (p->Data == item) {
                p->Data = newvalue;
                ++count;
            }
            p = p->Next;
        }
        return count;
    }

    ~List() {
        release();
    }
};


#endif //MYTONATEST_LIST_H
