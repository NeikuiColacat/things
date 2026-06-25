# agent桂电毕设自动完成skill

这是给桂电本科毕设同学使用的 Agent 辅助写作工具包。它用于让 Agent 帮你做论文规划、材料整理、初稿扩写、格式检查、DOCX/PDF 排版核验和最终提交清单检查。

它不是代写包。使用时必须基于自己的真实项目、代码、实验、截图、日志、文献和指导老师要求；不要让 Agent 编造实验结果、参考文献、签名、成绩表或项目功能。

## 目录

- `SKILL.md`：给 Codex/Agent 读取的主 skill 说明。
- `references/`：通用工作流、提示词、DOCX 检查清单、桂电 Word 排版避坑、officecli 安装建议。
- `assets/guet-official-templates/`：桂电官方格式要求、封面、声明、提交材料清单、英文翻译封面。
- `assets/citation-style/`：GB/T 7714 CSL 样式。
- `bundled-skills/`：通用论文规划、定稿、DOCX、Word 排版、officecli 操作技能。

## 建议安装

建议先准备这些工具：

```bash
sudo apt update
sudo apt install -y libreoffice pandoc poppler-utils
```

建议安装 Office CLI，方便 Agent 检查和修改 Word/PPT/Excel 文件：

```bash
curl -fsSL https://d.officecli.ai/install.sh | bash
officecli --version
```

如果 `officecli` 安装后找不到命令，重新打开终端再试。

## 推荐用法

把这个目录交给 Agent 后，可以这样说：

```text
请使用 ./agent桂电毕设自动完成skill 里的 SKILL.md 和 references，
根据我的真实项目代码、已有文档和学校模板，先做毕设论文规划和材料缺口清单。
不要编造实验和参考文献，所有结论都要能追溯到真实材料。
```

等材料齐了，再让 Agent 按章节写、按模板排版、导出 PDF 检查。

排版前建议先读：

```text
references/guet-word-layout-pitfalls.md
references/docx-final-checklist.md
```

## 最重要的原则

- 先整理真实材料，再写正文。
- 先做大纲和证据表，再扩写章节。
- 先核对引用，再生成参考文献。
- 先导出 PDF 看版式，再说排版完成。
- 最终提交前自己逐页检查，特别是封面、声明、目录、页眉页码、图表编号和参考文献。
