
<h1>Property Management System</h1>
<p>This repository contains the code for the Property Management System project. The system automates the process of buying and selling properties, managing property listings, and handling user accounts for buyers and sellers.</p>

<h2>Table of Contents</h2>
<ul>
      <li><a href="#project-description">Project Description</a></li>
        <li><a href="#features">Features</a></li>
        <li><a href="#technologies-used">Technologies Used</a></li>
        <li><a href="#installation">Installation</a></li>
        <li><a href="#usage">Usage</a></li>
        <li><a href="#database-schema">Database Schema</a></li>
        <li><a href="#contributing">Contributing</a></li>
        <li><a href="#license">License</a></li>
        <li><a href="#contact">Contact</a></li>
    </ul>

<h2 id="project-description">Project Description</h2>
<p>The Property Management System is designed to automate the process of buying and selling properties. This system allows users to manage property listings, buyers, and sellers efficiently. It provides features for adding, updating, deleting, and viewing property details, as well as managing user accounts for buyers and sellers.</p>

<h2 id="features">Features</h2>
<ul>
        <li><b>Property Management</b>
            <ul>
                <li>Add new properties</li>
                <li>Update existing property details</li>
                <li>Delete properties</li>
                <li>View property listings</li>
            </ul>
        </li>
        <li><b>User Management</b>
            <ul>
                <li>Register new buyers and sellers</li>
                <li>Update user details</li>
                <li>Delete user accounts</li>
                <li>View user information</li>
            </ul>
        </li>
        <li><b>Database Management</b>
            <ul>
                <li>Connect to a MySQL database</li>
                <li>Execute SQL queries for CRUD operations</li>
                <li>Handle database errors</li>
            </ul>
        </li>
    </ul>

<h2 id="technologies-used">Technologies Used</h2>
    <ul>
        <li><b>Programming Language:</b> C++</li>
        <li><b>Database:</b> MySQL</li>
        <li><b>Libraries:</b> MySQL Connector/C++ for database connectivity</li>
    </ul>

<h2 id="installation">Installation</h2>
<h3>Prerequisites</h3>
    <ul>
        <li><b>C++ Compiler:</b> Ensure you have a C++ compiler installed (e.g., GCC, MSVC).</li>
        <li><b>MySQL Server:</b> Install MySQL Server and create a database for the project.</li>
        <li><b>MySQL Connector/C++:</b> Download and install the MySQL Connector/C++ library.</li>
    </ul>

<h3>Steps</h3>
    <ol>
        <li><b>Clone the Repository</b>
            <pre><code>git clone https://github.com/your-username/property-management-system.git
cd property-management-system</code></pre>
        </li>
        <li><b>Configure the Database</b>
            <ul>
                <li>Create a MySQL database for the project:
                    <pre><code>CREATE DATABASE property_management;
USE property_management;</code></pre>
                </li>
                <li>Run the provided SQL script to set up the required tables:
                    <pre><code>mysql -u username -p property_management &lt; setup.sql</code></pre>
                </li>
            </ul>
        </li>
        <li><b>Build the Project</b>
            <ul>
                <li>Ensure that your C++ compiler can locate the MySQL Connector/C++ library.</li>
                <li>Compile the project:
                    <pre><code>g++ -o property_management main.cpp -lmysqlcppconn</code></pre>
                </li>
            </ul>
        </li>
        <li><b>Run the Application</b>
            <pre><code>./property_management</code></pre>
        </li>
    </ol>

<h2 id="usage">Usage</h2>
    <ul>
        <li><b>Add Property</b>
            <ul>
                <li>Enter the property details such as address, price, type, and status.</li>
            </ul>
        </li>
        <li><b>Update Property</b>
            <ul>
                <li>Modify existing property information using the property ID.</li>
            </ul>
        </li>
        <li><b>Delete Property</b>
            <ul>
                <li>Remove a property from the database using the property ID.</li>
            </ul>
        </li>
        <li><b>View Properties</b>
            <ul>
                <li>Display a list of all available properties.</li>
            </ul>
        </li>
        <li><b>Register User</b>
            <ul>
                <li>Create a new buyer or seller account with personal details.</li>
            </ul>
        </li>
        <li><b>Update User</b>
            <ul>
                <li>Edit user information based on the user ID.</li>
            </ul>
        </li>
        <li><b>Delete User</b>
            <ul>
                <li>Delete a user account using the user ID.</li>
            </ul>
        </li>
        <li><b>View Users</b>
            <ul>
                <li>List all registered buyers and sellers.</li>
            </ul>
        </li>
    </ul>

<h2 id="database-schema">Database Schema</h2>
    <ul>
        <li><b>Properties Table</b>
            <ul>
                <li><code>id</code> (INT): Primary key</li>
                <li><code>address</code> (VARCHAR): Property address</li>
                <li><code>price</code> (DECIMAL): Property price</li>
                <li><code>type</code> (VARCHAR): Type of property (e.g., house, apartment)</li>
                <li><code>status</code> (VARCHAR): Status of the property (e.g., available, sold)</li>
            </ul>
        </li>
        <li><b>Users Table</b>
            <ul>
                <li><code>id</code> (INT): Primary key</li>
                <li><code>name</code> (VARCHAR): User's name</li>
                <li><code>email</code> (VARCHAR): User's email</li>
                <li><code>role</code> (VARCHAR): User's role (buyer or seller)</li>
                <li><code>password</code> (VARCHAR): User's password (hashed)</li>
            </ul>
        </li>
    </ul>

<h2 id="contributing">Contributing</h2>
    <p>Contributions are welcome! Please fork the repository and create a pull request with your changes.</p>

<h2 id="license">License</h2>
    <p>This project is licensed under the MIT License. See the LICENSE file for details.</p>

<h2 id="contact">Contact</h2>
    <p>For any questions or issues, please contact:</p>
    <ul>
        <li><b>Name:</b> Sai Likhitha</li>
        <li><b>Email:</b> <a href="mailto:likhithakotapati9596@gmail.com">likhithakotapati9596@gmail.com</a></li>
    </ul>
</body>
</html>
