<h1>libExample</h1>
An automated library system for users and books.
Main classes are:
<ul>
   <li><a href="#libClass">LibOrganizer</a></li>
   <li><a href="#userclass">User</a></li>
   <li><a href="#bookclass">Book</a></li>
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
   <li><a href="#libconstructor">constuctor</a></li>
   <li><a href="#libBorrowfunc">borrowBook</a></li>
   <li><a href="#libReturnfunc">returnBook</a></li>
   <li><a href="#libRequestfunc">requestBook</a></li>
   <li><a href="#libBuyFunc">buyBook</a></li>
   <li><a href="#libAddUser">addUser</a></li>
   <li><a href="#libfindTitle">findBookByTitle</a></li>
   <li><a href="#libfindisbn">findBookByISBN</a></li>
   <li><a href="#libfindusername">findUserByName</a></li>
</ul>
<h3 id="libconstructor">- LibOrganizer(std::function<void(Book book)> buyBookFunction)</h3>
   <p>Paramter is a call-back function, to be called after every request after 50th request.</p>

<h3 id="libBorrowfunc">- void borrowBook(std::string userName, std::string BookTitle)</h3>
   <p>this function is to be called when a user called $userName borrows a book called $Booktitle.</p>

<h3 id="libReturnfunc">- void returnBook(std::string userName, std::string BookTitle)</h3>
   <p>this function is to be called when a user returns a book.</p>

<h3 id="libRequestfunc">- void requestBook(std::string BookTitle, std::string author, std::string ISBN)</h3>
   <p>This function is to be called when user requests a book (throws BookException::hasBeenRequestedFromThisUser).</p>

<h3 id="libBuyFunc">- Book& buyBook(std::string title, std::string author, std::string ISBN)</h3>
   <p>this function is to be called when a new Book is bought to be added to the repository.</p>

<h3 id="libAddUser">- User& addUser(std::string name)</h3>
   <p>adds new user to to librarry</p>

<h3 id="libfindTitle">- Book& findBookPerTitle(const std::string& title)</h3>
   <p>returns the book with corresponding title from the repo.</p>

<h3 id="libfindisbn">- Book& findBookPerISBN(const std::string& ISBN)</h3>
   <p>returns the book with corresponding ISBN from the repo.</p>

<h3 id="libfindusername">- User& findUserPerName(const std::string& userName)</h3>
   <p>returns the user with corresponding name from the repo.</p>
</div>
<br>
<div>
<h2 id="userclass">User:</h2>
   User Class implements a library user. It has the functionality.
   It has "UserException" enum class and throws one of its values in case of error:
<ul>
   <li>reachedMaxNumberOfBooks</li>
   <li>noSuchBook</li>
</ul>
   It has the following functions:
<ul>
   <li><a href="#userConstructor">constructor</a></li>
   <li><a href="#userBorrowFunc">borrowBook</a></li>
   <li><a href="#userReturnFunc">returnBook</a></li>
   <li><a href="#userGetName">getName</a></li>
   <li><a href="#userTostring">toString</a></li>
</ul>
<h3 id="userConstructor">- User(std::string name)</a></h3>
   <p>creates a new user with User.name = name</p>
<h3 id="userBorrowFunc">- void borrowBook(Book& book)</h3>
   <p>add the borrowed book to the list of borrowed books of the user(a list of 10 books</p>
<h3 id="userReturnFunc">- void returnBook(Book& book)</h3>
   <p>remove the book from the list of borrowed books of the user</p>
<h3 id="userGetName">- std::string getName()</h3>
   <p>return name of the user</p>
<h3 id="userTostring">- std::string toString()</h3>
   <p>return user data as a string</p>
   
</div>
<br/>
<div>
<h2 id="bookclass">Book:</h2>
   Book class represent a book with a titile, author, ISBN and a potential borrower.
   It has "BookException" enum class and throws one of its values as exceptions:
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
   <li><a href="#bookConstructor">constructor</a></li>
   <li><a href="#bookRequestFunc">request</a></li>
   <li><a href="#bookIsAvailable">isAvailable</a></li>
   <li><a href="#bookBorrowFunc">borrow</a></li>
   <li><a href="#bookReturnFunc">returnBook</a></li>
   <li><a href="#bookBuyFromWaitingList">buyFromWaitingList</a></li>
   <li><a href="#bookToString">toString</a></li>
   <li><a href="#bookGetUser">getUser</a></li>
   <li><a href="#bookGetTitle">getTitle</a></li>
   <li><a href="#bookGetISBN">getISBN</a></li>
   <li><a href="#bookGetAuthor">getAuthor</a></li>
   <li><a href="#bookGetStatus">getStatus</a></li>
</ul>
<h3 id="bookConstructor">- Book(std::string title, std::string author, std::string ISBN, BookStatus status)</h3>
   <p>creates a new book with given parameters.</p>
<h3 id="bookRequestFunc">- int request(User* user)</h3>
   <p>increases request counter if user hasn't already requested and returns the new val.</p>
<h3 id="bookIsAvailable">- bool isAvailable()</h3>
   <p>return true if book status is available (already bought and not borrowed).</p>
<h3 id="bookBorrowFunc">- void borrow(User* user)</h3>
   <p>change book status to borrowed and saved the borrowing user.</p>
<h3 id="bookReturnFunc">- int returnBook()</h3>
   <p>change book status to available.</p>
<h3 id="bookBuyFromWaitingList">- void buyFromWaitingList()</h3>
   <p>change book status from requested to availalbe</p>
<h3 id="bookToString">- std::string toString()</h3>
   <p>return book data as a string</p>
<h3 id="bookGetUser">- User* getUser()</h3>
   <p>shows the book borrower or throws exception if not borrowed</p>
<h3 id="bookGetTitle">- std::string getTitle()</h3>
   <p>returns book title</p>
<h3 id="bookGetISBN">- std::string getISBN()</h3>
   <p>returns book isbn</p>
<h3 id="bookGetAuthor">- std::string getAuthor()</h3>
   <p>returns book author</p>
<h3 id="bookGetStatus">- BookStatus getStatus()</h3>
   <p>return book status of data Type Book::Status</p>
</div>
