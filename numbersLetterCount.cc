/**
 * Developed by Arnau Bagó Castro
 * 
 * Linkedin: https://es.linkedin.com/in/arnaubago
 * Github: https://github.com/tknbr/euler
 * 
 * Part of the Project Euler problems ( https://projecteuler.net )
 *
 * Number letter counts
 *
 * If the numbers 1 to 5 are written out in words: one, two, three, four, five, then there are 3 + 3 + 5 + 4 + 4 = 19  
 * letters used in total.
 *
 * If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?
 *
 * NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and forty-two) contains 23 letters and 115 (  
 * one hundred and fifteen) contains 20 letters. The use of "and" when writing out numbers is in compliance with       
 * British usage.
 *
 */

 /**
  * This problem is more of finding certain patterns than to compute an algorithm so I'm just going to explain
  * how this is solved. 
  *
  * Numbers from 1 to 9: There is no patter here. You just need to write the numbers down and count. The sequence  
  * is:  3 + 3 + 5 + 4 + 4 + 3 + 5 + 5 + 4 = 36
  *
  * Numbers from 10-19: Same as before, we have no patter, sequence is: 3 + 6 + 6 + 8 + 8 + 7 + 7 + 9 + 8 + 8 = 70
  *
  * Numbers from 20-99: Here we have a pattern. First we need to write down all the multiples of 10 ( this will not 
  * be a pattern ). Then we can add 8 times sequence from 1 to 9. Final sequence is: 
  * 10*(6 + 6 + 5 + 5 + 5 + 7 + 6 + 6) + 8*36 = 748
  * 
  * Numbers from 100-999: several patterns.
  *						1. Numbers from 1-9 will be repeated 100 times each i.e. one hundred ... two hunderd ... 
  *						2. Numbers from 1-99 will be repeated 9 times. 
  *						3. The word "hundred" will be repeated 9 times. 
  *						4. The wrod "hundred and" will be repeated 9*99 times. 
  * Total = 36*100 + 9*854 + 7*9 + 9*99*10 = 20259
  * 
  * Number "one thousand" has 11 letters. 
  *
  * Total sum = 36+70+748+20259+11= 21124
  */