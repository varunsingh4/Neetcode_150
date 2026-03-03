# 🧠 How to Identify a Backtracking Pattern (Subset Problems)

When you see a **“subset”** question, 90% of the time it’s a **backtracking problem**.

This guide helps you quickly recognize the backtracking pattern in interviews.

---

## 🔎 How to Identify a Backtracking (Subset) Question

---

### 1️⃣ The Question Asks to Generate *All Possible Combinations*

Look for keywords like:

- “Return all subsets”
- “Generate all combinations”
- “Find all possible ways”
- “List all valid sequences”
- “Power set”

### 👉 Example Prompts

- “Return all subsets of an array.”
- “Find all combinations that sum to target.”
- “Generate all valid parentheses.”

These usually scream **backtracking**.

---

### 2️⃣ You Must Explore Choices at Each Step

If at every index you have a decision like:

- Include it
- Exclude it

That forms a classic **backtracking decision tree**.

### Example

For:


[1,2,3]


At each number:

- Take it  
- Don’t take it  

This creates:

    []
  /     \
1         []

/ \ /
2 [] 2 []


That tree structure = **Backtracking**

---

### 3️⃣ Constraints + “All Solutions”

If the question says:

- “Find all valid …”
- “Subject to constraints”
- “You can reuse elements”
- “Avoid duplicates”

👉 That’s **backtracking with pruning**.

Common examples:

- Subsets II (handling duplicates)
- Combination Sum
- N-Queens
- Sudoku

---

### 4️⃣ Small Input Size (Very Important Trick)

If:


n <= 20


That usually means:

- You can generate `2^n` subsets
- They expect an exponential solution

Examples:


n <= 15
n <= 20


👉 That’s your green signal for backtracking.

---

## 🧠 Mental Checklist

Ask yourself:

- Do I need to try every possibility?
- Does each step involve a choice?
- Do I need to explore and undo choices?
- Am I building answers step-by-step?

If the answer is **YES** → It’s backtracking.

---

## 🔥 Golden Backtracking Pattern

1. Choose  
2. Explore  
3. Undo  

That’s the core idea behind subset problems.

---

## 🚀 Summary

If a problem asks for:

- All subsets
- All combinations
- All valid arrangements

And the input size is small...

You’re almost certainly dealing with **Backtracking**.
