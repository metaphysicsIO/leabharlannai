#include <iostream>
#include <string>

struct Book
{
    std::string Title;
    std::string Author;
    std::string ISBN;
    std::string Genre;
};

class LinkedList
{
    public:
        LinkedList();
        virtual ~LinkedList();
        void Append(Book book);
        void Remove(Book book);
        void PrintAll();
        Book Search(std::string s);
        int Size();
    private:
        struct Node{
            Book book;
            Node *next;
            Node *prev;

            /* Constructor */
            Node()
            {
                next = nullptr;
                prev = nullptr;
            }

            /* Initalizer */
            Node(Book m_book)
            {
                book = m_book;
            }
        };

        Node *m_head;
        Node *m_tail;
        int m_size = 0;
};

LinkedList::LinkedList()
{
    /* Constructor */
    m_head = m_tail = nullptr;
}

LinkedList::~LinkedList()
{
    //TODO: make destructor
    ;;
}

void LinkedList::Append(Book book)
{
    //TODO: make Append()
    Node *node = new Node(book);

    if(m_head == nullptr)
    {
        m_head = node;
    }else
    {
        if(m_tail != nullptr)
        {
            m_tail->next = node;
        }
    }

    m_tail = node;

    m_size++;

}

void LinkedList::Remove(Book book)
{
    //TODO: make Remove()
    ;;
}

Book LinkedList::Search(std::string s)
{
    //TODO: make Search() by title / author / isbn
    Node *curr = m_head;

    while(curr != nullptr)
    {
        if(curr->book.ISBN.compare(s) == 0)
        {
            return curr->book;
        }
        curr = curr->next;
    }
    //TODO: Return when there is no match.
}

void LinkedList::PrintAll()
{
    //TODO: make PrintAll()
    Node *curr = m_head;

    /* iterate through nodes */
    while(curr != nullptr)
    {
        std::cout << curr->book.Title << "\t";
        std::cout << curr->book.Author << "\t";
        std::cout << curr->book.Genre << "\t";
        std::cout << curr->book.ISBN << std::endl;
        curr = curr->next;
    }
}

int LinkedList::Size()
{
    return m_size;
}

Book getBook()
{
    Book book;

    std::cout << "Enter title: ";
    std::cin.ignore();
    getline(std::cin, book.Title);

    std::cout << "Enter author: ";
    getline(std::cin, book.Author);

    std::cout << "Enter genre: ";
    getline(std::cin, book.Genre);

    std::cout << "Enter isbn: ";
    getline(std::cin, book.ISBN);

    return book;
}

int main()
{
    Book book;
    LinkedList myLinkedList;

    int choice = 0;
    while(choice != 9)
    {
        std::cout << "Library Menu:" << std::endl;
        std::cout << "\t1. Enter book" << std::endl;
        std::cout << "\t2. Display all books" << std::endl;
        std::cout << "\t3. Search for book" << std::endl;
        std::cout << "\t9. Exit" << std::endl;
        std::cin >> choice;

        switch(choice)
        {
            case 1:
                book = getBook();
                myLinkedList.Append(book);
                break;
            case 2:
                myLinkedList.PrintAll();
                break;
            case 3:
                //TODO: Add Search Function
                std::cout << "TODO: Add Search Function" << std::endl;
                break;
            default:
                std::cout << "How did you get here?" << std::endl;
                break;
        }
    }

    std::cout << "Goodbye." << std::endl;

    return 0;
}
