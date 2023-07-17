<!DOCTYPE HTML>
<html>
 <h1> CSC212 DSA Project by Andrew Ou, Andrew Langille, Sean Reth, Tanya Li </h1>
  
<body>
  
  <h2> Overview
  </h2>
<p>
With the help of the robust and effective text search tool String Search 2, users can locate instances of a specific search string inside a given text or group of texts. It is suited for a variety of applications because it is made to be quick, easy to use, and adaptable.
</p>

<h3> Algorithm KMP (Knuth-Morris-Pratt)
</h3>
<p>
Name of Function: KMP <br>

Two strings are provided: one to check (the target text) and the other to search for (the search string). <br>

Return Type: Integer Vector <br>

What it does: The Knuth-Morris-Pratt string search technique is carried out mostly by the KMP function. The search string and the target text are inputted, and the algorithm outputs a vector of numbers that represents the starting indexes of all instances of the search string in the target text.
</p>

<h3> KMP Helper
</h3>
<p>
Name of Function: KMP Helper<br>

Two strings are provided: one to check (the target text) and one to search for up to a predetermined break point.<br>

Return Type: Integer (Index)<br>

What it does: After a failed check, the KMP algorithm uses the KMP Helper function to establish the index from which to begin looking for matches. The effectiveness of the KMP algorithm is increased by this enhancement.
</p>

<h3> Return KMP Efficiency
</h3>
<p>
Function Name: Return KMP Efficiency <br>

Return Type: Integer <br>

What it does: The Return KMP Efficiency function calculates the KMP algorithm's efficiency by returning the number of loops or computation time.
</p>

<h3> Boyer-Moore Algorithm
</h3>
<p>
Function Name: Boyer-Moore <br>
  
Two strings are provided: one to check (the target text) and the other to search for (the search string).<br>

Return Type: Integer Vector<br>

What it does: The Boyer-Moore function serves as the foundation for the Boyer-Moore string search algorithm. The search string and the target text are inputted, and the algorithm outputs a vector of numbers that represents the starting indexes of all instances of the search string in the target text.
</p>

<h3>BMCompare
</h3>
<p>
Function Name: BMCompare <br>

Two strings are provided: one to check (the target text) and one to search for up to a predetermined break point.<br>

Return Type: Integer<br>

What it does: After a failed check, the Boyer-Moore algorithm uses the BMCompare function to determine the index from which to start looking for matches. The Boyer-Moore algorithm is made more effective by this enhancement.
</p>

<h3>Return BM Efficiency
</h3>
<p>
Function Name: Return BM Efficiency <br>

Return Type: integer<br>

What it does: The Return BM Efficiency function calculates the Boyer-Moore algorithm's efficiency by reporting the number of loops or computation time.
</p>

</body>

<h2>Usage
</h2>
<p>
To discover instances of the search string in the target text using the String Search 2 library, you can call the KMP function or the Boyer-Moore function with the required parameters. The Return KMP Efficiency and Return BM Efficiency functions can be used to calculate each algorithm's efficiency.<br>

To carry out quick and effective string search operations, feel free to investigate and include this library into your projects. Please don't hesitate to get in touch with the above contributors if you run into any problems or have ideas for enhancements. Happy looking!
</p>

</html>
