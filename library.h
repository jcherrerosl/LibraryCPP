#ifndef LIBRARY_H
# define LIBRARY_H

# include <iostream>
# include <string>
# include <vector>

class Book
{
  public:
	Book(const std::string& title, const std::string& author, int year)
		: title(title), author(author), year(year)
	{
	}
	void print() const
	{
		std::cout << "El título es: " << title << std::endl;
		std::cout << "El autor es: " << author << std::endl;
		std::cout << "El año es: " << year << std::endl;
	}
    const std::string& getTitle() const
    {
        return (title);
    }
    const std::string& getAuthor() const
    {
        return (author);
    }
  private:
	const std::string title;
	const std::string &author;
	int year;
};

class BookStore
{
  public:
    void addBook(const Book& book)
    {
        books.push_back(book);
    }
    void printBooks() const
    {
        for (const Book& b : books)
            b.print();
    }
    bool findBookByTitle(const std::string& title) const
    {
        for (const Book& b : books)
        {
            if (b.getTitle() == title)
            {
                std::cout << "Libro encontrado" << std::endl;
                return (true);
            }
        }
        std::cout << "El título introducido no está disponible" << std::endl;
        return (false);
    }
    std::vector<Book> authorCollection(const std::string& author) const
    {
        std::vector<Book> collection;
        for (const Book& b : books)
        {
            if (b.getAuthor() == author)
            {
                collection.push_back(b);
            }
        }
        return (collection);
    }
  private:
    std::vector<Book> books;
};

#endif