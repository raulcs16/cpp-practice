
# control flow

2.9
(This is an extension of an exercise from Chapter 1.) The Babylonian algorithm to compute the square root of a positive number n is as follows:
Make a guess at the answer (you can pick n/2 as your initial guess).
Compute r = n / guess.
Set guess= (guess + r) / 2.
Go back to step 2 for as many iterations as necessary. The more steps 2 and 3 are repeated, the closer guess will become to the square root of n.
Write a program that inputs a double for n, iterates through the Babylonian algorithm until the guess is within 1% of the previous guess, and outputs the answer as a double to two decimal places. Your answer should be accurate even for large values of n.

2.12

This problem is based on a “Nifty Assignment” by Steve Wolfman (<http://nifty.stanford.edu/2006/wolfman-pretid>). Consider lists of numbers from real-life data sources, for example, a list containing the number of students enrolled in different course sections, the number of comments posted for different Facebook status updates, the number of books in different library holdings, the number of votes per precinct, etc. It might seem like the leading digit of each number in the list should be 1–9 with an equally likely probability. However, Benford’s Law states that the leading digit is 1 about 30% of the time and drops with larger digits. The leading digit is 9 only about 5% of the time.
Write a program that tests Benford’s Law. Collect a list of at least one hundred numbers from some real-life data source and enter them into a text file. Your program should loop through the list of numbers and count how many times 1 is the first digit, 2 is the first digit, etc. For each digit, output the percentage it appears as the first digit.
If you read a number into the string variable named strNum then you can access the first digit as a char by using strNum[0]. This is described in more detail in Chapter 9.
