<h1>libExample</h1>
An automated library system for users and books.
Main classes are:
<ul>
<li href="#libclass">LibOrganizer</li>
<li href="#userclass">User</li>
<li href="#bookclass">Book</li>
</ul>
<br>
<div>
<h2 id="libClass">LibOrganizer:</h2>
Is the main part of the library. Organizes people and books in an efficient way.
It has "LibExceptions" enum class and throws one of its values in case of error:
<ul>
   <li>bookNotFound</li>
   <li>bookNotAvailable</li>
   <li>bookTitleAlreadyExists</li>
   <li>bookISBNAlreadyExists</li>
   <li>bookAlreadyBought</li>
   <li>userAlreadyExists</li>
   <li>userNotFound</li>
</ul>   
It has also the following functions:
<ul>
   <li>constuctor</li>
   <li>borrowBook</li>
   <li>returnBook</li>
   <li>requestBook</li>
   <li>buyBook</li>
   <li>addUser</li>
   <li>findBookByISBN</li>
   <li>findBookByTitle</li>
   <li>findUserByName</li>
</ul>
<h3>- LibOrganizer(std::function<void(Book book)> buyBookFunction)</h3>
   <p>Paramter is a call-back function, to be called after every request after 50th request.</p>

<h3>- void borrowBook(std::string userName, std::string BookTitle)</h3>
   <p>this function is to be called when a user called $userName borrows a book called $Booktitle.</p>

<h3>- void returnBook(std::string userName, std::string BookTitle)</h3>
   <p>this function is to be called when a user returns a book.</p>

<h3>- void requestBook(std::string BookTitle, std::string author, std::string ISBN)</h3>
   <p>This function is to be called when user requests a book (throws BookException::hasBeenRequestedFromThisUser).</p>

<h3>- Book& buyBook(std::string title, std::string author, std::string ISBN)</h3>
   <p>this function is to be called when a new Book is bought to be added to the repository.</p>

<h3>- User& addUser(std::string name)</h3>
   <p>adds new user to to librarry</p>

<h3>- Book& findBookPerTitle(const std::string& title)</h3>
   <p>returns the book with corresponding title from the repo.</p>

<h3>- Book& findBookPerISBN(const std::string& ISBN)</h3>
   <p>returns the book with corresponding ISBN from the repo.</p>

<h3>- User& findUserPerName(const std::string& userName)</h3>
   <p>returns the user with corresponding name from the repo.</p>
</div>
<br>
<div>
<h2 id="userclass">User:</h2>
</div>
<br/>
<div>
<h2 id="bookclass">Book:</h2>
   Book class represent a book with a titile, author, ISBN and a potential borrower.
   It has "BookException" enum class and throws on of its values as exceptions:
<ul>
   <li>notAvailable</li>
   <li>notInRequest</li>
   <li>notBorrowed</li>
   <li>hasBeenRequestedFromThisUser</li>
</ul>
   It has also "BookStatus" enum class which has the following potential values:
<ul>
   <li>available</li>
   <li>borrowed</li>
   <li>inRequest</li>
</ul>
   It offers the following functions:
<ul>
   <li>constructor</li>
   <li>request</li>
   <li>isAvailable</li>
   <li>borrow</li>
   <li>returnBook</li>
   <li>buyFromWaitingList</li>
   <li>toString</li>
   <li>getUser</li>
   <li>getTitle</li>
   <li>getISBN</li>
   <li>getAuthor</li>
   <li>getStatus</li>
</ul>
<h3>- Book(std::string title, std::string author, std::string ISBN, BookStatus status)</h3>
   <p>creates a new book with given parameters.</p>
<h3>- int request(User* user)</h3>
   <p>increases request counter if user hasn't already requested and returns the new val.</p>
<h3>- bool isAvailable()</h3>
   <p>return true if book status is available (already bought and not borrowed).</p>
<h3>- void borrow(User* user)</h3>
   <p>change book status to borrowed and saved the borrowing user.</p>
<h3>- int returnBook()</h3>
   <p>change book status to available.</p>
<h3>- void buyFromWaitingList()</h3>
   <p>change book status from requested to availalbe</p>
<h3>- std::string toString()</h3>
   <p>return book data as a string</p>
<h3>- User* getUser()</h3>
   <p>shows the book borrower or throws exception if not borrowed</p>
<h3>- std::string getTitle()</h3>
   <p>returns book title</p>
<h3>- std::string getISBN()</h3>
   <p>returns book isbn</p>
<h3>- std::string getAuthor()</h3>
   <p>returns book author</p>
<h3>- BookStatus getStatus()</h3>
   <p>return book status of data Type Book::Status</p>
</div>
