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
Is the main part of the library, organizes people and books in an efficient way has the following functions:
<ul>
<li>Constuctor</li>
<li>borrowBook</li>
<li>returnBook</li>
<li>requestBook</li>
<li>findByISBN</li>
<li>findByTitle</li>
<li>buyBook</li>
<li>addUser</li>
</ul>
   <span>
  <h3>LibOrganizer(std::function<void(Book book)> buyBookFunction)</h3>
    <p>Paramter is a call-back function, to be called after every request after 50th request.</p>
  <h3>void borrowBook(std::string userName, std::string BookTitle)</h3>
    <p>The function called when a borrow action happens.
    Exceptions:
    <ol>
      <li></li>
      <li></li>
    </ol>
  <h3>LibOrganizer(std::function<void(Book book)> buyBookFunction)</h3>
    <p>Paramter is a call-back function, to be called after every request after 50th request.</p>
</div>
<div>
<h2>User:</h2>
Is the main part of the library, organizes people and books in an efficient way has the following functions:
<ul>
<li>LibOrganizer</li>
<li>User</li>
<li>Book</li>
</ul>
</div>
<div>
<h2>Book:</h2>
Is the main part of the library, organizes people and books in an efficient way has the following functions:
<ul>
<li>LibOrganizer</li>
<li>User</li>
<li>Book</li>
</ul>
</div>
