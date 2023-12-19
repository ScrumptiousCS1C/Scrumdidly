# 2D Shape Renderer

## Team

Spencer - Scrum Master lead Ui/Class hierarchy designer (sorting algorithms, move, shape editor, main screen, delete shape etc) 
Romina - Product owner (Doxygen documentation, backlogs) Shape Hierarchy
Melina - Shape Hierarchy design and implementation Draw and Canvas implementation
Ethan - Parser and Serializer design and implementation
Xandro - Parser and Serializer design and implementation
Arman - Login widget permissions, and contact us/ testimonials
Jibran - Login widget permissions, logo and contact us/ testimonials
Chase - UML diagrams and documentation for shape hierarchy and program structure

### Description

This project is a 2D shape renderer designed in Qt using agile methods.  Using modular design, I designated specific tasks for each teammember to develop 
elements of the project in paralell with one another.  This way, if roadblocks occured during development, it was easy to facilitate changes to make elements of the project 
work better together.  

#### How to Log In

After launching the program, you will recieve a prompt asking you to log in using credentials.  To open the program with administrator priviledges (i.e. edit, 
add, delete shapes etc.) login with username: `Admin` and password `CS1CADMIN`.  To log in as a user: `Scrumptious` and `CS1C` as the password.  Any other combination of 
entries will be rejected

##### How to Draw

Shapes will be automatically loaded from shapes.txt after successful login.  Pressing the `Draw` button on the ui will cause the program to draw all of the shapes that were
saved from the parser.  Clicking the shape dropdown list will allow you to open a shape editor, saving the changes made to any of the shapes in the program and reflecting them
on the canvas.  Selecting `delete` within the shape editor will remove the shape from the canvas and the vector of shapes.  If `new` is selected from the dropdown, a new shape
will be added to the vector and displayed on the canvas and within the list.  Shapes in the list may be sorted by clicking any of the relative sorting buttons (Area, Perimeter,
Shape ID)

###### Saving

To save your project, simply click the `save` button and choose the directory on your local machine you would like to save the file on.  The serializer prepares a document that
can now be read in future projects, just make sure to change what file your parser is looking for!

####### Thank You

Thank you so much for looking at this project, countless hours were spent designing this program, much was learned.  
