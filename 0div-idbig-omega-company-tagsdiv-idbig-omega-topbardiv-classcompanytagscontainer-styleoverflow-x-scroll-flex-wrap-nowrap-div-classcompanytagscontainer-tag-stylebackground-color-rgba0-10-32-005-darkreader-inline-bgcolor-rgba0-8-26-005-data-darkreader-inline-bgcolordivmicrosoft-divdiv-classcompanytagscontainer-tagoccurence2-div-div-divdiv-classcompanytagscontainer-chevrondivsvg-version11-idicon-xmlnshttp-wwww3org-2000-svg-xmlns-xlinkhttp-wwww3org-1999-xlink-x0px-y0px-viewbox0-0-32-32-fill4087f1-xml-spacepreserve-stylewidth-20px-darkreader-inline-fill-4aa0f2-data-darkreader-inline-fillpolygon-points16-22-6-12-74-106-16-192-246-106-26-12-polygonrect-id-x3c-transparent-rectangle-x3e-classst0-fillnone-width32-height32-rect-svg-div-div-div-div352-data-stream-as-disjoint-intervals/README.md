<h2><a href="https://leetcode.com/problems/data-stream-as-disjoint-intervals/"><div id="big-omega-company-tags"><div id="big-omega-topbar"><div class="companyTagsContainer" style="overflow-x: scroll; flex-wrap: nowrap;"><div class="companyTagsContainer--tag" style="background-color: rgba(0, 10, 32, 0.05); --darkreader-inline-bgcolor: rgba(0, 8, 26, 0.05);" data-darkreader-inline-bgcolor=""><div>Microsoft</div><div class="companyTagsContainer--tagOccurence">2</div></div></div><div class="companyTagsContainer--chevron"><div><svg version="1.1" id="icon" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px" viewBox="0 0 32 32" fill="#4087F1" xml:space="preserve" style="width: 20px; --darkreader-inline-fill: #4aa0f2;" data-darkreader-inline-fill=""><polygon points="16,22 6,12 7.4,10.6 16,19.2 24.6,10.6 26,12 "></polygon><rect id="_x3C_Transparent_Rectangle_x3E_" class="st0" fill="none" width="32" height="32"></rect></svg></div></div></div></div>352. Data Stream as Disjoint Intervals</a></h2><h3>Hard</h3><hr><div><p>Given a data stream input of non-negative integers <code>a<sub>1</sub>, a<sub>2</sub>, ..., a<sub>n</sub></code>, summarize the numbers seen so far as a list of disjoint intervals.</p>

<p>Implement the <code>SummaryRanges</code> class:</p>

<ul>
	<li><code>SummaryRanges()</code> Initializes the object with an empty stream.</li>
	<li><code>void addNum(int value)</code> Adds the integer <code>value</code> to the stream.</li>
	<li><code>int[][] getIntervals()</code> Returns a summary of the integers in the stream currently as a list of disjoint intervals <code>[start<sub>i</sub>, end<sub>i</sub>]</code>. The answer should be sorted by <code>start<sub>i</sub></code>.</li>
</ul>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input</strong>
["SummaryRanges", "addNum", "getIntervals", "addNum", "getIntervals", "addNum", "getIntervals", "addNum", "getIntervals", "addNum", "getIntervals"]
[[], [1], [], [3], [], [7], [], [2], [], [6], []]
<strong>Output</strong>
[null, null, [[1, 1]], null, [[1, 1], [3, 3]], null, [[1, 1], [3, 3], [7, 7]], null, [[1, 3], [7, 7]], null, [[1, 3], [6, 7]]]

<strong>Explanation</strong>
SummaryRanges summaryRanges = new SummaryRanges();
summaryRanges.addNum(1);      // arr = [1]
summaryRanges.getIntervals(); // return [[1, 1]]
summaryRanges.addNum(3);      // arr = [1, 3]
summaryRanges.getIntervals(); // return [[1, 1], [3, 3]]
summaryRanges.addNum(7);      // arr = [1, 3, 7]
summaryRanges.getIntervals(); // return [[1, 1], [3, 3], [7, 7]]
summaryRanges.addNum(2);      // arr = [1, 2, 3, 7]
summaryRanges.getIntervals(); // return [[1, 3], [7, 7]]
summaryRanges.addNum(6);      // arr = [1, 2, 3, 6, 7]
summaryRanges.getIntervals(); // return [[1, 3], [6, 7]]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>0 &lt;= value &lt;= 10<sup>4</sup></code></li>
	<li>At most <code>3 * 10<sup>4</sup></code> calls will be made to <code>addNum</code> and <code>getIntervals</code>.</li>
	<li>At most <code>10<sup>2</sup></code>&nbsp;calls will be made to&nbsp;<code>getIntervals</code>.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Follow up:</strong> What if there are lots of merges and the number of disjoint intervals is small compared to the size of the data stream?</p>
</div>