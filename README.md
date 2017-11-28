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
<li>findByISBN</li>
<li>findByTitle</li>
<li>addUser</li>
</ul>
   <span>
  <h3>LibOrganizer(std::function<void(Book book)> buyBookFunction)</h3>
    <p>Paramter is a call-back function, to be called after every request after 50th request.</p>
  <h3>void borrowBook(std::string userName, std::string BookTitle)</h3>
     <p>this function is to be called when a user called $userName borrows a book called $Booktitle.</p>
  <h3>void returnBook(std::string userName, std::string BookTitle)</h3>
     <p>this function is to be called when a user returns a book</p>
  <h3>	void requestBook(std::string BookTitle, std::string author, std::string ISBN)</h3>
     <p>This function is to be called when user requests a book.</p>
</div>
<div>
<h2>User:</h2>
<h2>Book:</h2>
