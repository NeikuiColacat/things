---
name: "word-docx-format"
description: "Read, write, inspect, generate, and format Microsoft Word .docx documents. Use when Codex needs to create or edit thesis documents, preserve Word formatting, inspect templates/styles, convert markdown or structured notes into .docx, update tables/figures/captions, manage Chinese thesis typography, or automate document assembly with python-docx/docxtpl/docxcompose/docx2python/mammoth/pypandoc."
---

# Word DOCX Format

## Core Rules

- Prefer working from an existing `.docx` template when layout matters.
- Do not overwrite the only copy of a Word document. Write outputs with a new filename unless the user explicitly asks to replace it.
- Inspect styles before editing: paragraph styles, heading styles, table styles, margins, headers/footers, captions, and numbering often carry thesis requirements.
- Use `python-docx` for creating and editing normal document content.
- Use `docxtpl` when filling placeholders in a prepared template.
- Use `docxcompose` when combining multiple `.docx` files while preserving section formatting.
- Use `docx2python` or `mammoth` for text extraction and structure inspection.
- Use direct OOXML edits only when `python-docx` cannot express the required feature.

## Workflow

1. Identify the source document or template.
2. Run `scripts/docx_inspect.py <file.docx>` when style/format preservation matters.
3. Decide the edit mode:
   - Simple content creation: `python-docx`
   - Template filling: `docxtpl`
   - Merge documents: `docxcompose`
   - Extract text/outline: `docx2python` or `mammoth`
   - Markdown to Word: `pypandoc` if `pandoc` is installed; otherwise build with `python-docx`
4. Write output to a new `.docx` file.
5. Re-open or inspect the result and verify key sections, tables, headings, captions, and style names.

## Thesis Formatting Defaults

For Chinese undergraduate thesis work, treat the school-provided `.doc/.docx` files as the authority. When no explicit template is available:

- Use A4 page size.
- Keep chapter headings and body text style-based, not manual formatting scattered across runs.
- Prefer Chinese fonts such as SimSun/宋体 for body text and SimHei/黑体 for headings when requested by the template.
- Keep figures and tables numbered consistently, with captions close to their objects.
- Preserve cover pages, declarations, signatures, page headers/footers, and section breaks from official templates.

## Common Commands

```bash
# Inspect a document structure and styles
python ~/.codex/skills/word-docx-format/scripts/docx_inspect.py input.docx

# Activate this project's uv environment before document automation
source .venv/bin/activate
```

## Available Word Tooling In This Project

For `/home/neiku/graduate_project`, assume the following tools are installed and prefer them in this order:

- `scripts/docx_inspect.py`: inspect `.docx` paragraphs, headings, style names, tables, sections, margins, headers, and footers before editing.
- `python-docx`: default writer/editor for thesis body text, headings, captions, tables, pictures, sections, and style assignment.
- `docxtpl`: fill prepared Word templates for cover pages, declarations, abstracts, or other fixed-layout pages.
- `docxcompose`: merge chapter-level `.docx` files while preserving section formatting.
- `docx2python`: extract text, tables, headers, footers, footnotes, and structure from `.docx` for checks.
- `mammoth`: convert `.docx` to clean HTML-like text for fast content inspection.
- `markitdown[docx,pdf]`: convert example `.docx` and `.pdf` documents to Markdown for fast reading and structure search; for this project, generated example Markdown lives under `templates/markitdown_md/`.
- `lxml`: inspect or patch OOXML only when high-level libraries cannot express the needed Word feature.
- `pypandoc` plus system `pandoc`: convert Markdown/HTML to `.docx`, preferably with a reference `.docx` when preserving thesis styles.
- LibreOffice / `soffice`: headless `.doc`/`.docx` opening, repair, conversion, and PDF export for final rendering checks.
- Poppler tools: use `pdfinfo` for page count/metadata and `pdftotext` for PDF text verification after export.
- Noto CJK fonts: available as the Chinese font fallback during headless PDF export.

Project writing workflow:

- `thesis.md` is the content source for drafting and Git diff.
- `毕业论文.docx` is the single maintained Word deliverable and formatting authority.
- Keep cover pages, declarations, TOC fields, headers/footers, captions, and final typography in Word.
- When Markdown chapters stabilize, sync content into `毕业论文.docx` while preserving `GUET-标题1/2/3` styles.

Project verification commands:

```bash
source .venv/bin/activate
python /home/neiku/.codex/skills/word-docx-format/scripts/docx_inspect.py "毕业论文.docx"
python /home/neiku/.codex/skills/word-docx-format/scripts/docx_inspect.py "templates/优秀往年毕业论文往年范例.docx"
soffice --headless --convert-to pdf --outdir /tmp "毕业论文.docx"
pdfinfo /tmp/毕业论文.pdf
pdftotext /tmp/毕业论文.pdf -
```

For a project that maintains Markdown as the source and Word as the final
deliverable, regenerate Word with the project-local build script when available:

```bash
source .venv/bin/activate
python tools/build_thesis_docx.py
```

Then update the TOC, normalize sections/headers/footers if the project script
supports it, and only then export/check PDF. Do not claim the layout is ready
until the exported PDF has been inspected.

## Thesis Project Reminder

Use the student's actual project repository, logs, screenshots, requirements,
experiments, and adviser feedback as the source of truth. Do not invent project
features, experimental numbers, datasets, citations, signatures, or review
results. If evidence is missing, write a gap list and ask the student to provide
or generate real materials.

The single maintained thesis document should be `毕业论文.docx`; do not create
versioned thesis copies such as `修正版` or dated `.docx` files unless explicitly
requested. Use Git commits for history. Keep school templates, source materials,
and generated outputs in clearly separated directories.

For engineering or software-system undergraduate theses, a safe starting outline
is:

```text
1 绪论
2 相关理论及关键技术
3 系统可行性与需求分析
4 系统总体设计
5 核心模块设计与实现
6 系统测试与结果分析
7 总结与展望
```
