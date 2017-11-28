<h1>libExample</h1>
An automated library system for users and books.
Main classes are:
<ul>
<li>LibOrganizer</li>
<li>User</li>
<li>Book</li>
</ul>
<div>
<h2>LibOrganizer:</h2>
Is the main part of the library. Organizes people and books in an efficient way. Has the following functions:
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
<h2>User:</h2>
</div>
<br/>
<div>
<h2>Book:</h2>
   Book class represent a book with a titile, author, ISBN and a potential borrower. It offers following functions:
<ul>
   <li>request</li>
   <li>isAvailable</li>
   <li>borrow</li>
   <li>returnBook</li>
   <li>buyFromWaitingList</li>
   <li>returnBook</li>
   <li>toString</li>
   <li>getUser</li>
   <li>getTitle</li>
   <li>getISBN</li>
   <li>getAuthor</li>
   <li>getStatus</li>
</ul>
</div>
