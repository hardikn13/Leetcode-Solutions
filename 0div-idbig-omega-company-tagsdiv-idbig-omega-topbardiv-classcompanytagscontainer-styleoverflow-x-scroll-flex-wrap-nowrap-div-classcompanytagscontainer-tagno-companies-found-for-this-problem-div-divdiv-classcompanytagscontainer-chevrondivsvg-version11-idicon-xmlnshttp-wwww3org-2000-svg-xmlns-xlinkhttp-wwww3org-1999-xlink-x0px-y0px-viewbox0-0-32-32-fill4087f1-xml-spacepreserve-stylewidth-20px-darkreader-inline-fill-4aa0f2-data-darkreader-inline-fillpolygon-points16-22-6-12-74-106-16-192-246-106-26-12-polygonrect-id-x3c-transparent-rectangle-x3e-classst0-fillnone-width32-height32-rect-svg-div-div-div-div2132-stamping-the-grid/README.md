<h2><a href="https://leetcode.com/problems/stamping-the-grid/"><div id="big-omega-company-tags"><div id="big-omega-topbar"><div class="companyTagsContainer" style="overflow-x: scroll; flex-wrap: nowrap;"><div class="companyTagsContainer--tag">No companies found for this problem</div></div><div class="companyTagsContainer--chevron"><div><svg version="1.1" id="icon" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px" viewBox="0 0 32 32" fill="#4087F1" xml:space="preserve" style="width: 20px; --darkreader-inline-fill: #4aa0f2;" data-darkreader-inline-fill=""><polygon points="16,22 6,12 7.4,10.6 16,19.2 24.6,10.6 26,12 "></polygon><rect id="_x3C_Transparent_Rectangle_x3E_" class="st0" fill="none" width="32" height="32"></rect></svg></div></div></div></div>2132. Stamping the Grid</a></h2><h3>Hard</h3><hr><div><p>You are given an <code>m x n</code> binary matrix <code>grid</code> where each cell is either <code>0</code> (empty) or <code>1</code> (occupied).</p>

<p>You are then given stamps of size <code>stampHeight x stampWidth</code>. We want to fit the stamps such that they follow the given <strong>restrictions</strong> and <strong>requirements</strong>:</p>

<ol>
	<li>Cover all the <strong>empty</strong> cells.</li>
	<li>Do not cover any of the <strong>occupied</strong> cells.</li>
	<li>We can put as <strong>many</strong> stamps as we want.</li>
	<li>Stamps can <strong>overlap</strong> with each other.</li>
	<li>Stamps are not allowed to be <strong>rotated</strong>.</li>
	<li>Stamps must stay completely <strong>inside</strong> the grid.</li>
</ol>

<p>Return <code>true</code> <em>if it is possible to fit the stamps while following the given restrictions and requirements. Otherwise, return</em> <code>false</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/11/03/ex1.png" style="width: 180px; height: 237px;">
<pre><strong>Input:</strong> grid = [[1,0,0,0],[1,0,0,0],[1,0,0,0],[1,0,0,0],[1,0,0,0]], stampHeight = 4, stampWidth = 3
<strong>Output:</strong> true
<strong>Explanation:</strong> We have two overlapping stamps (labeled 1 and 2 in the image) that are able to cover all the empty cells.
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/11/03/ex2.png" style="width: 170px; height: 179px;">
<pre><strong>Input:</strong> grid = [[1,0,0,0],[0,1,0,0],[0,0,1,0],[0,0,0,1]], stampHeight = 2, stampWidth = 2 
<strong>Output:</strong> false 
<strong>Explanation:</strong> There is no way to fit the stamps onto all the empty cells without the stamps going outside the grid.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[r].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= m * n &lt;= 2 * 10<sup>5</sup></code></li>
	<li><code>grid[r][c]</code> is either <code>0</code> or <code>1</code>.</li>
	<li><code>1 &lt;= stampHeight, stampWidth &lt;= 10<sup>5</sup></code></li>
</ul>
</div>