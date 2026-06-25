---
name: guet-thesis-auto-writer
description: Use when helping Guilin University of Electronic Technology undergraduate students plan, draft, revise, format, and verify graduation thesis materials with agents, GUET official templates, Word/DOCX workflows, citations, and final submission checks. Trigger for requests about 桂电本科毕业设计论文, 毕设论文自动化写作, thesis outline, school template formatting, DOCX cleanup, reference formatting, review reports, or agent-assisted thesis completion.
---

# GUET Thesis Auto Writer

## Scope

Use this skill to assist GUET undergraduate thesis work from real student-owned materials:

- project/code/document evidence collection;
- thesis outline and chapter plan;
- first draft expansion from verified materials;
- revision against school format and review feedback;
- Word/DOCX layout checks and PDF rendering checks;
- reference and citation cleanup;
- final submission checklist.

Do not fabricate experiments, datasets, screenshots, citations, signatures, grades, or review forms. If a student has no real project evidence, first produce a gap list and a collection plan instead of inventing content.

## Start Here

Read only the references needed for the current task:

- `references/guet-thesis-workflow.md`: end-to-end agent workflow.
- `references/agent-prompts.md`: reusable prompts for students.
- `references/docx-final-checklist.md`: Word/PDF layout and submission checks.
- `references/guet-word-layout-pitfalls.md`: common Word layout pitfalls and fixes from prior GUET thesis formatting work.
- `references/officecli-install.md`: optional Office CLI installation and usage.

Assets:

- `assets/guet-official-templates/`: official GUET cover, declaration, format rules, submission checklist, and translation cover.
- `assets/citation-style/`: GB/T 7714 CSL style.

Bundled generic skills:

- `bundled-skills/academic-paper-strategist`
- `bundled-skills/academic-paper-composer`
- `bundled-skills/docx`
- `bundled-skills/word-docx-format`
- `bundled-skills/officecli`

## Standard Workflow

1. Audit inputs: project repo, existing draft, school template, reference list, figures, tables, and review reports.
2. Build an evidence map: every thesis claim should point to real code, data, screenshot, log, experiment result, requirement document, or cited source.
3. Produce an outline: chapter titles, section goals, needed figures/tables, and missing evidence.
4. Draft by section: write from the evidence map, keep claims conservative, and mark missing items explicitly.
5. Format with the GUET template: cover, declaration, abstracts, TOC, body, acknowledgements, references, and appendices.
6. Verify: citation keys, reference order, figure/table numbering, heading levels, page breaks, DOCX integrity, PDF rendering, and school submission checklist.
7. Finalize: keep one final DOCX/PDF pair and a short change report.

## Guardrails

- Keep student identity placeholders until the student intentionally fills final metadata.
- Do not include private agent traces, temporary logs, model caches, or unrelated project files in submission packages.
- Use official templates as formatting references; do not rewrite school declaration wording casually.
- Prefer primary sources and official documentation for technical claims.
- Treat AI-generated text as a draft requiring student review, factual checking, and advisor approval.
