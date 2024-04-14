<h2><a href="https://leetcode.com/problems/latest-time-you-can-obtain-after-replacing-characters/"><div id="big-omega-company-tags"><div id="big-omega-topbar"><div class="companyTagsContainer" style="overflow-x: scroll; flex-wrap: nowrap;"><div class="companyTagsContainer--tag">No companies found for this problem</div></div><div class="companyTagsContainer--chevron"><div><svg version="1.1" id="icon" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px" viewBox="0 0 32 32" fill="#4087F1" xml:space="preserve" style="width: 20px; --darkreader-inline-fill: #4aa0f2;" data-darkreader-inline-fill=""><polygon points="16,22 6,12 7.4,10.6 16,19.2 24.6,10.6 26,12 "></polygon><rect id="_x3C_Transparent_Rectangle_x3E_" class="st0" fill="none" width="32" height="32"></rect></svg></div></div></div></div>3114. Latest Time You Can Obtain After Replacing Characters</a></h2><h3>Easy</h3><hr><div><p>You are given a string <code>s</code> representing a 12-hour format time where some of the digits (possibly none) are replaced with a <code>"?"</code>.</p>

<p>12-hour times are formatted as <code>"HH:MM"</code>, where <code>HH</code> is between <code>00</code> and <code>11</code>, and <code>MM</code> is between <code>00</code> and <code>59</code>. The earliest 12-hour time is <code>00:00</code>, and the latest is <code>11:59</code>.</p>

<p>You have to replace <strong>all</strong> the <code>"?"</code> characters in <code>s</code> with digits such that the time we obtain by the resulting string is a <strong>valid</strong> 12-hour format time and is the <strong>latest</strong> possible.</p>

<p>Return <em>the resulting string</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">s = "1?:?4"</span></p>

<p><strong>Output:</strong> <span class="example-io">"11:54"</span></p>

<p><strong>Explanation:</strong> The latest 12-hour format time we can achieve by replacing <code>"?"</code> characters is <code>"11:54"</code>.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">s = "0?:5?"</span></p>

<p><strong>Output:</strong> <span class="example-io">"09:59"</span></p>

<p><strong>Explanation:</strong> The latest 12-hour format time we can achieve by replacing <code>"?"</code> characters is <code>"09:59"</code>.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>s.length == 5</code></li>
	<li><code>s[2]</code> is equal to the character <code>":"</code>.</li>
	<li>All characters except <code>s[2]</code> are digits or <code>"?"</code> characters.</li>
	<li>The input is generated such that there is <strong>at least</strong> one time between <code>"00:00"</code> and <code>"11:59"</code> that you can obtain after replacing the <code>"?"</code> characters.</li>
</ul>
</div>