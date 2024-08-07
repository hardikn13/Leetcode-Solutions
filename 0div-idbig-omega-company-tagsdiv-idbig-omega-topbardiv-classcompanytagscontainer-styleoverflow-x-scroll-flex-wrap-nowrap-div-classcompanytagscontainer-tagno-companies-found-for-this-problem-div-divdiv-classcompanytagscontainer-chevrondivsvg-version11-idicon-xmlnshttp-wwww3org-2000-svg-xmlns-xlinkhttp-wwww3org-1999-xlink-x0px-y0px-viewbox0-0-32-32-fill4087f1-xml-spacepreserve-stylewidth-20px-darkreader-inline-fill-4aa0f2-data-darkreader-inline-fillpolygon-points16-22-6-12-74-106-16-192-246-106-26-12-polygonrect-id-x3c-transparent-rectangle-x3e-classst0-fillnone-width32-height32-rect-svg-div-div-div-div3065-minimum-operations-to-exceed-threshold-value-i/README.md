<h2><a href="https://leetcode.com/problems/minimum-operations-to-exceed-threshold-value-i/"><div id="big-omega-company-tags"><div id="big-omega-topbar"><div class="companyTagsContainer" style="overflow-x: scroll; flex-wrap: nowrap;"><div class="companyTagsContainer--tag">No companies found for this problem</div></div><div class="companyTagsContainer--chevron"><div><svg version="1.1" id="icon" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px" viewBox="0 0 32 32" fill="#4087F1" xml:space="preserve" style="width: 20px; --darkreader-inline-fill: #4aa0f2;" data-darkreader-inline-fill=""><polygon points="16,22 6,12 7.4,10.6 16,19.2 24.6,10.6 26,12 "></polygon><rect id="_x3C_Transparent_Rectangle_x3E_" class="st0" fill="none" width="32" height="32"></rect></svg></div></div></div></div>3065. Minimum Operations to Exceed Threshold Value I</a></h2><h3>Easy</h3><hr><div><p>You are given a <strong>0-indexed</strong> integer array <code>nums</code>, and an integer <code>k</code>.</p>

<p>In one operation, you can remove one occurrence of the smallest element of <code>nums</code>.</p>

<p>Return <em>the <strong>minimum</strong> number of operations needed so that all elements of the array are greater than or equal to</em> <code>k</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [2,11,10,1,3], k = 10
<strong>Output:</strong> 3
<strong>Explanation:</strong> After one operation, nums becomes equal to [2, 11, 10, 3].
After two operations, nums becomes equal to [11, 10, 3].
After three operations, nums becomes equal to [11, 10].
At this stage, all the elements of nums are greater than or equal to 10 so we can stop.
It can be shown that 3 is the minimum number of operations needed so that all elements of the array are greater than or equal to 10.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [1,1,2,4,9], k = 1
<strong>Output:</strong> 0
<strong>Explanation:</strong> All elements of the array are greater than or equal to 1 so we do not need to apply any operations on nums.</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> nums = [1,1,2,4,9], k = 9
<strong>Output:</strong> 4
<strong>Explanation:</strong> only a single element of nums is greater than or equal to 9 so we need to apply the operations 4 times on nums.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 50</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= k &lt;= 10<sup>9</sup></code></li>
	<li>The input is generated such that there is at least one index <code>i</code> such that <code>nums[i] &gt;= k</code>.</li>
</ul>
</div>