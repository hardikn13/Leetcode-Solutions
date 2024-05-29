<h2><a href="https://leetcode.com/problems/sum-of-digit-differences-of-all-pairs/"><div id="big-omega-company-tags"><div id="big-omega-topbar"><div class="companyTagsContainer" style="overflow-x: scroll; flex-wrap: nowrap;"><div class="companyTagsContainer--tag">No companies found for this problem</div></div><div class="companyTagsContainer--chevron"><div><svg version="1.1" id="icon" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px" viewBox="0 0 32 32" fill="#4087F1" xml:space="preserve" style="width: 20px; --darkreader-inline-fill: #4aa0f2;" data-darkreader-inline-fill=""><polygon points="16,22 6,12 7.4,10.6 16,19.2 24.6,10.6 26,12 "></polygon><rect id="_x3C_Transparent_Rectangle_x3E_" class="st0" fill="none" width="32" height="32"></rect></svg></div></div></div></div>3153. Sum of Digit Differences of All Pairs</a></h2><h3>Medium</h3><hr><div><p>You are given an array <code>nums</code> consisting of <strong>positive</strong> integers where all integers have the <strong>same</strong> number of digits.</p>

<p>The <strong>digit difference</strong> between two integers is the <em>count</em> of different digits that are in the <strong>same</strong> position in the two integers.</p>

<p>Return the <strong>sum</strong> of the <strong>digit differences</strong> between <strong>all</strong> pairs of integers in <code>nums</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [13,23,12]</span></p>

<p><strong>Output:</strong> 4</p>

<p><strong>Explanation:</strong><br>
We have the following:<br>
- The digit difference between <strong>1</strong>3 and <strong>2</strong>3 is 1.<br>
- The digit difference between 1<strong>3</strong> and 1<strong>2</strong> is 1.<br>
- The digit difference between <strong>23</strong> and <strong>12</strong> is 2.<br>
So the total sum of digit differences between all pairs of integers is <code>1 + 1 + 2 = 4</code>.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [10,10,10,10]</span></p>

<p><strong>Output:</strong> <span class="example-io">0</span></p>

<p><strong>Explanation:</strong><br>
All the integers in the array are the same. So the total sum of digit differences between all pairs of integers will be 0.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt; 10<sup>9</sup></code></li>
	<li>All integers in <code>nums</code> have the same number of digits.</li>
</ul>
</div>