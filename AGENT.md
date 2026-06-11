# AGENT.md — Contribution Instructions for dsa-wiki

> **This file contains mandatory instructions for any AI agent or contributor working on this repository.**
> Every rule below uses "ALWAYS" or "NEVER" intentionally — these are non-negotiable standards.

---

## Overview

`dsa-wiki` is a curated collection of LeetCode solutions where every problem folder contains:
- One or more **commented solution files** (`.cpp`, `.py`, `.js`, etc.)
- A **comprehensive `README.md`**
- Optionally, an **interactive HTML demo** and **concept images**

Every time a new solution is added or an existing one is modified, BOTH the solution file AND the README **must** be updated. Never do one without the other.

---

## 1. Solution File — Comment Standards

### ALWAYS add a file-level header block

Every solution file MUST begin with a multi-line comment block containing:

```cpp
/*
 * LeetCode #<NUMBER> — <Problem Title>
 * <LeetCode URL>
 *
 * APPROACH: <Short approach name, e.g. "Dual Frequency Arrays", "Binary Search on Window">
 * ──────────────────────────────────────────────────────────────
 * <2–4 sentences explaining the core idea and why it works.>
 * <Mention any key insight or non-obvious trick.>
 *
 * TIME  : O(...)  — <brief justification, e.g. "one linear pass over n elements">
 * SPACE : O(...)  — <brief justification, e.g. "constant 26-slot array">
 */
```

### ALWAYS comment every logical section of the code

Group related lines into sections. ALWAYS add a comment above each group explaining **what** the block does and **why** — not just **what** the line says.

```cpp
// Fast-exit: different lengths can never be anagrams
// (avoids unnecessary work when sizes already differ)
if (s.length() != t.length()) return false;
```

> ❌ Bad comment: `// increment` (restates the code)
> ✅ Good comment: `// s[i] - 'a' maps the character to a 0-based index: 'a'→0, 'b'→1, …, 'z'→25`

### ALWAYS explain non-obvious tricks and index math

If you use a formula, bit operation, offset, or type-cast that isn't immediately obvious to a new reader, ALWAYS add an inline or above-line comment explaining it.

```cpp
// s[i] - 'a' maps char to index: 'a'→0, 'b'→1, …, 'z'→25
st[s[i] - 'a']++;

// Bit shift equivalent to (lo + hi) / 2, avoids integer overflow
int mid = lo + ((hi - lo) >> 1);
```

### ALWAYS add a closing alternative/extension block

At the end of the file, ALWAYS include a commented block describing:
1. **One alternative approach** with code snippet (if it exists)
2. **One edge case or constraint extension** (e.g. "for Unicode inputs, use unordered_map")

```cpp
/*
 * ALTERNATIVE: <Alternative approach name>
 * ─────────────────────────────────────────
 * <brief description>
 *
 *   <compact code snippet>
 *
 * <Trade-off vs current approach>
 */
```

### ALWAYS use consistent comment style per language

| Language | Block comment style | Inline comment |
|---|---|---|
| C++ | `/* … */` for headers, `// …` for inline | `//` |
| Python | `"""…"""` docstrings for functions, `#` for inline | `#` |
| JavaScript | `/** … */` JSDoc for functions, `//` for inline | `//` |

---

## 2. README.md — Required Sections

Every `README.md` MUST contain ALL of the following sections in this exact order:

### Section 1 — Header (ALWAYS required)

```markdown
# <Problem Title>

**LeetCode #<NUMBER>** · [LeetCode](<url>) · [NeetCode](<url>)

- **Difficulty:** Easy | Medium | Hard
- **Categories:** <comma-separated tags>
- **Time Complexity:** O(...)
- **Space Complexity:** O(...)
```

### Section 2 — Problem Statement (ALWAYS required)

ALWAYS include:
- A 1–2 sentence plain-English problem description
- At least **2 examples** with `Input:` and `Output:` shown in a code block

```markdown
## Problem Statement

Given …, return …

**Examples:**
\```
Input:  s = "anagram", t = "nagaram"  →  Output: true
Input:  s = "rat",     t = "car"      →  Output: false
\```
```

### Section 3 — Intuition (ALWAYS required)

ALWAYS add a short "Intuition" section (3–6 sentences) explaining **why** the approach works **before** showing any code. This is the most important section for learning.

```markdown
## Intuition

<Why does this approach solve the problem? What key observation makes it possible?>
```

### Section 4 — Approach (ALWAYS required)

ALWAYS include:
- The approach name as the heading
- A prose walkthrough (not just code)
- A concise **code snippet** (pseudocode-style, not the raw solution, with inline comments)

```markdown
## Approach: <Approach Name>

<Prose explanation>

\```cpp
// annotated pseudocode or simplified core logic
\```
```

### Section 5 — Complexity Table (ALWAYS required)

ALWAYS use a Markdown table with a **Reason** column explaining *why* the complexity is what it is:

```markdown
## Complexity

| | Value | Reason |
|---|---|---|
| **Time**  | O(N) | <justification> |
| **Space** | O(1) | <justification> |
```

### Section 6 — Edge Cases (ALWAYS required)

ALWAYS list edge cases in a table. Cover at minimum: empty inputs, equal inputs, maximum-size inputs, and tie-breaking scenarios.

```markdown
## Edge Cases

| Scenario | Result |
|---|---|
| Empty strings `s = "", t = ""` | `true` |
| `s == t` (identical) | `true` |
| Different lengths | `false` |
| … | … |
```

### Section 7 — Files Table (ALWAYS required)

ALWAYS include a table listing every file in the problem folder and what it contains:

```markdown
## Files

| File | Description |
|---|---|
| [`solution.cpp`](./solution.cpp) | Main C++ solution with full inline comments |
| [`demo.html`](./demo.html)       | Step-by-step interactive visualization |
| [`concept.png`](./concept.png)   | Visual explanation of the core concept |
```

### Section 8 — Related Problems (ALWAYS required)

ALWAYS list at least **3 related LeetCode problems** with links and a one-line description of how they relate:

```markdown
## Related Problems

- [Group Anagrams (LC #49)](https://leetcode.com/problems/group-anagrams/) — Same frequency-count pattern, applied to grouping
- [Find All Anagrams in a String (LC #438)](…) — Sliding window with the same technique
- [Ransom Note (LC #383)](…) — Subset frequency check using the same array pattern
```

### Optional Sections (add when applicable)

| Section | When to add |
|---|---|
| `## Alternative Approach` | When a meaningfully different O-complexity approach exists |
| `## Unicode / Follow-up Extension` | When the solution has known constraints worth expanding on |
| `## Interactive Demo` | When an `.html` visualization file exists in the folder |

---

## 3. Naming Conventions

| Item | Convention | Example |
|---|---|---|
| Solution file | `<approach-name>.cpp` (kebab-case) | `frequency-array.cpp`, `binary-search.cpp` |
| HTML demo | `<problem-slug>_<approach>.html` | `find_k_closest_binary_search.html` |
| Concept image | `concept.png` | `concept.png` |
| README | Always exactly `README.md` | — |

NEVER name a solution file `solution.cpp` or `main.cpp` — the name MUST reflect the approach used.

---

## 4. Workflow — Adding a New Solution

ALWAYS follow these steps in order. Never skip a step:

```
1. Create the problem folder: dsa-wiki/<problem-slug>/
2. Create the solution file with:
   - File-level header block (approach, complexity)
   - Section comments on every logical group
   - Inline comments on all non-obvious lines
   - Closing alternative/extension block
3. Create (or fully rewrite) README.md with ALL 8 required sections
4. (Optional) Add HTML demo or concept image
5. git add <problem-slug>/
6. git commit -m "<problem-slug>: add <approach> solution + README"
7. git push origin main
```

---

## 5. Quick Checklist (use before every commit)

Before committing, verify ALL of the following:

- [ ] Solution file has a **header block** with approach name, time, and space complexity
- [ ] Every logical section has a **why** comment (not just what)
- [ ] All non-obvious tricks, formulas, and index math are **explained inline**
- [ ] A **closing alternative/extension block** is present
- [ ] README has all **8 required sections**: Header, Problem Statement, Intuition, Approach, Complexity, Edge Cases, Files, Related Problems
- [ ] README has **2+ examples** in the Problem Statement
- [ ] README **Complexity table** has a Reason column
- [ ] README **Edge Cases table** covers empty/equal/max-size/tie-break scenarios
- [ ] README **Files table** lists every file in the folder
- [ ] README **Related Problems** has 3+ entries with links and descriptions
- [ ] Solution filename uses **approach-based kebab-case** (not `solution.cpp`)
- [ ] `git commit` message follows the format: `<problem-slug>: add <approach> solution + README`
