<h2><a href="https://leetcode.com/problems/valid-word/"><div id="big-omega-company-tags"><div id="big-omega-topbar"><div class="companyTagsContainer" style="overflow-x: scroll; flex-wrap: nowrap;"><div class="companyTagsContainer--tag">No companies found for this problem</div></div><div class="companyTagsContainer--chevron"><div><svg version="1.1" id="icon" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px" viewBox="0 0 32 32" fill="#4087F1" xml:space="preserve" style="width: 20px; --darkreader-inline-fill: #4aa0f2;" data-darkreader-inline-fill=""><polygon points="16,22 6,12 7.4,10.6 16,19.2 24.6,10.6 26,12 "></polygon><rect id="_x3C_Transparent_Rectangle_x3E_" class="st0" fill="none" width="32" height="32"></rect></svg></div></div></div></div>3136. Valid Word</a></h2><h3>Easy</h3><hr><div><p>A word is considered <strong>valid</strong> if:</p>

<ul>
	<li>It contains a <strong>minimum</strong> of 3 characters.</li>
	<li>It consists of the digits 0-9, and the uppercase and lowercase English letters. (Not necessary to have all of them.)</li>
	<li>It includes <strong>at least</strong> one <strong>vowel</strong>.</li>
	<li>It includes <strong>at least</strong> one <strong>consonant</strong>.</li>
</ul>

<p>You are given a string <code>word</code>.</p>

<p>Return <code>true</code> if <code>word</code> is valid, otherwise, return <code>false</code>.</p>

<p><strong>Notes:</strong></p>

<ul>
	<li><code>'a'</code>, <code>'e'</code>, <code>'i'</code>, <code>'o'</code>, <code>'u'</code>, and their uppercases are <strong>vowels</strong>.</li>
	<li>A <strong>consonant</strong> is an English letter that is not a vowel.</li>
</ul>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">word = "234Adas"</span></p>

<p><strong>Output:</strong> <span class="example-io">true</span></p>

<p><strong>Explanation:</strong></p>

<p>This word satisfies the conditions.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">word = "b3"</span></p>

<p><strong>Output:</strong> <span class="example-io">false</span></p>

<p><strong>Explanation:</strong></p>

<p>The length of this word is fewer than 3, and does not have a vowel.</p>
</div>

<p><strong class="example">Example 3:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">word = "a3$e"</span></p>

<p><strong>Output:</strong> <span class="example-io">false</span></p>

<p><strong>Explanation:</strong></p>

<p>This word contains a <code>'$'</code> character and does not have a consonant.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= word.length &lt;= 20</code></li>
	<li><code>word</code> consists of English uppercase and lowercase letters, digits, <code>'@'</code>, <code>'#'</code>, and <code>'$'</code>.</li>
</ul>
</div>