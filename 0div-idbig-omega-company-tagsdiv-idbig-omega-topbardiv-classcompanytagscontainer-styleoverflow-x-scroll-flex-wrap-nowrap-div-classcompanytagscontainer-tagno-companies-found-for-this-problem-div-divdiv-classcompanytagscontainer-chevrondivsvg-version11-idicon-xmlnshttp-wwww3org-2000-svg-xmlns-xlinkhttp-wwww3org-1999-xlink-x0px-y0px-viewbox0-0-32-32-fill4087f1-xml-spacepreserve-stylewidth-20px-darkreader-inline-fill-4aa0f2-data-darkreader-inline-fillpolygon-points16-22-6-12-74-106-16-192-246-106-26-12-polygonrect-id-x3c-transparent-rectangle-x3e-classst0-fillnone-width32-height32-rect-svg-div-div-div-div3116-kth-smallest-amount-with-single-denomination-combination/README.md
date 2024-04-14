<h2><a href="https://leetcode.com/problems/kth-smallest-amount-with-single-denomination-combination/"><div id="big-omega-company-tags"><div id="big-omega-topbar"><div class="companyTagsContainer" style="overflow-x: scroll; flex-wrap: nowrap;"><div class="companyTagsContainer--tag">No companies found for this problem</div></div><div class="companyTagsContainer--chevron"><div><svg version="1.1" id="icon" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px" viewBox="0 0 32 32" fill="#4087F1" xml:space="preserve" style="width: 20px; --darkreader-inline-fill: #4aa0f2;" data-darkreader-inline-fill=""><polygon points="16,22 6,12 7.4,10.6 16,19.2 24.6,10.6 26,12 "></polygon><rect id="_x3C_Transparent_Rectangle_x3E_" class="st0" fill="none" width="32" height="32"></rect></svg></div></div></div></div>3116. Kth Smallest Amount With Single Denomination Combination</a></h2><h3>Hard</h3><hr><div><p>You are given an integer array <code>coins</code> representing coins of different denominations and an integer <code>k</code>.</p>

<p>You have an infinite number of coins of each denomination. However, you are <strong>not allowed</strong> to combine coins of different denominations.</p>

<p>Return the <code>k<sup>th</sup></code> <strong>smallest</strong> amount that can be made using these coins.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block" style="border-color: var(--border-tertiary); border-left-width: 2px; color: var(--text-secondary); font-size: 0.875rem; margin-bottom: 1rem; margin-top: 1rem; overflow: visible; padding-left: 1rem; --darkreader-inline-color: var(--darkreader-text--text-secondary); --darkreader-inline-border: var(--darkreader-border--border-tertiary);" data-darkreader-inline-color="" data-darkreader-inline-border="">
<p><strong>Input:</strong> <span class="example-io" style="
    font-family: Menlo,sans-serif;
    font-size: 0.85rem;
">coins = [3,6,9], k = 3</span></p>

<p><strong>Output:</strong> <span class="example-io" style="
    font-family: Menlo,sans-serif;
    font-size: 0.85rem;
"> 9</span></p>

<p><strong>Explanation:</strong> The given coins can make the following amounts:<br>
Coin 3 produces multiples of 3: 3, 6, 9, 12, 15, etc.<br>
Coin 6 produces multiples of 6: 6, 12, 18, 24, etc.<br>
Coin 9 produces multiples of 9: 9, 18, 27, 36, etc.<br>
All of the coins combined produce: 3, 6, <u><strong>9</strong></u>, 12, 15, etc.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block" style="border-color: var(--border-tertiary); border-left-width: 2px; color: var(--text-secondary); font-size: 0.875rem; margin-bottom: 1rem; margin-top: 1rem; overflow: visible; padding-left: 1rem; --darkreader-inline-color: var(--darkreader-text--text-secondary); --darkreader-inline-border: var(--darkreader-border--border-tertiary);" data-darkreader-inline-color="" data-darkreader-inline-border="">
<p><strong>Input:</strong><span class="example-io" style="
    font-family: Menlo,sans-serif;
    font-size: 0.85rem;
"> coins = [5,2], k = 7</span></p>

<p><strong>Output:</strong><span class="example-io" style="
    font-family: Menlo,sans-serif;
    font-size: 0.85rem;
"> 12 </span></p>

<p><strong>Explanation:</strong> The given coins can make the following amounts:<br>
Coin 5 produces multiples of 5: 5, 10, 15, 20, etc.<br>
Coin 2 produces multiples of 2: 2, 4, 6, 8, 10, 12, etc.<br>
All of the coins combined produce: 2, 4, 5, 6, 8, 10, <u><strong>12</strong></u>, 14, 15, etc.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= coins.length &lt;= 15</code></li>
	<li><code>1 &lt;= coins[i] &lt;= 25</code></li>
	<li><code>1 &lt;= k &lt;= 2 * 10<sup>9</sup></code></li>
	<li><code>coins</code> contains pairwise distinct integers.</li>
</ul>
</div>