<!DOCTYPE HTML>
<html>
 <h1> CSC212 Project by Andrew Ou, Andrew Langille, Sean Reth, Tanya Li </h1>
  
<body>
  
  <h2> Overview
  </h2>
<p>
With the help of the robust and effective text search tool String Search 2, users can locate instances of a specific search string inside a given text or group of texts. It is suited for a variety of applications because it is made to be quick, easy to use, and adaptable.
</p>

<h3><b>Algorithm KMP (Knuth-Morris-Pratt)</b> 
</h3>
<p>
Name of Function: KMP <br>

Two strings are provided: one to check (the target text) and the other to search for (the search string). <br>

Return Type: Integer Vector <br>

What it does: The Knuth-Morris-Pratt string search technique is carried out mostly by the KMP function. The search string and the target text are inputted, and the algorithm outputs a vector of numbers that represents the starting indexes of all instances of the search string in the target text.
</p>

<h3> <b>KMP Helper</b>
</h3>
<p>
Name of Function: KMP Helper<br>

Two strings are provided: one to check (the target text) and one to search for up to a predetermined break point.<br>

Return Type: Integer (Index)<br>

What it does: After a failed check, the KMP algorithm uses the KMP Helper function to establish the index from which to begin looking for matches. The effectiveness of the KMP algorithm is increased by this enhancement.
</p>

<h3> creatSPTable
</h3>
<p>
Name of Function: creatSPT<br>

One string is provided: the pattern for which the SPTable needs to be created.<br>

Return Type: Integer Vector<br>

What it does: The createSPTable function generates the SPTable which stores the longest suffixes and prefixes at any point which can then be used by the KMP Helper to skip checking some indexes.
</p>

<h3> <b>Return FI Efficiency</b>
</h3>
<p>
Function Name: Return Find Index Efficiency <br>

Return Type: Integer <br>

What it does: The Return KMP Efficiency function calculates the KMP algorithm's efficiency by returning the number of loops or computation time.
</p>

<h3> <b>Return SPT Efficiency</b>
</h3>
<p>
Function Name: Return SPT Efficiency <br>

Return Type: Integer <br>

What it does: The Return SPT function returns the amount of loops it took to create the SPTable.
</p>

<h3> <b>Get Run time</b>
</h3>
<p>
Function Name: get_runTime <br>

Return Type: Integer <br>

What it does: Returns the amount of time it took for the find index function to compltely run.
</p>

<h3> <b>Boyer-Moore Algorithm</b>
</h3>
<p>
Function Name: Boyer-Moore <br>
  
Two strings are provided: one to check (the target text) and the other to search for (the search string).<br>

Return Type: Integer Vector<br>

What it does: The Boyer-Moore function serves as the foundation for the Boyer-Moore string search algorithm. The search string and the target text are inputted, and the algorithm outputs a vector of numbers that represents the starting indexes of all instances of the search string in the target text.
</p>

<h3> <b>BMCompare</b>
</h3>
<p>
Function Name: BMCompare <br>

Two strings are provided: one to check (the target text) and one to search for up to a predetermined break point.<br>

Return Type: Integer<br>

What it does: After a failed check, the Boyer-Moore algorithm uses the BMCompare function to determine the index from which to start looking for matches. The Boyer-Moore algorithm is made more effective by this enhancement.
</p>

<h3> <b>Return BM Efficiency</b>
</h3>
<p>
Function Name: Return BM Efficiency <br>

Return Type: integer<br>

What it does: The Return BM Efficiency function calculates the Boyer-Moore algorithm's efficiency by reporting the number of loops or computation time.
</p>

<h3> <b>Regular Substring Search</b>
</h3>
<p>
Function Name: regularSS <br>

Return Type: integer<br>

What it does: The class uses a naive approach for substring matching, where it checks each possible starting position in the text and compares characters one by one with the pattern. While this approach is straightforward, it may not be the most efficient for large texts or patterns. More advanced algorithms like Knuth-Morris-Pratt (KMP) or Boyer-Moore could be more suitable for larger scale and performance-critical substring searches.
</p>

</body>

<h2>Usage
</h2>
<p>
To discover instances of the search string in the target text using the String Search 2 library, you can call the KMP function or the Boyer-Moore function with the required parameters. The Return KMP Efficiency and Return BM Efficiency functions can be used to calculate each algorithm's efficiency.
</p>

<h2>Compiling Instructions
</h2>
<p>
To compile the code and create an executable named 'main', open your terminal or command prompt and navigate to the directory containing the source files (main.cpp, KMP.cpp, and boyerMoore.cpp). Then, use the following command: <br>

g++ main.cpp KMP.cpp boyerMoore.cpp regularSS.cpp -o main <br>

This command will compile the source files and link them to create the 'main' executable. To run the executable, use the following command:<br>

./main<br>

Feel free to investigate and include this library into your projects for quick and effective string search operations. Please don't hesitate to get in touch with the above contributors if you run into any problems or have ideas for enhancements. Happy searching!
</p>

</html>
