# officecli 建议安装

`officecli` 是一个命令行 Office 文档工具，适合让 Agent 检查和修改 `.docx`、`.pptx`、`.xlsx` 文件。它不是必须项，但很适合做毕设文档排版和终稿检查。

## 安装

Linux/macOS：

```bash
curl -fsSL https://d.officecli.ai/install.sh | bash
officecli --version
```

Windows PowerShell：

```powershell
irm https://d.officecli.ai/install.ps1 | iex
officecli --version
```

如果安装后命令不可用，重新打开终端。

## 常用命令

```bash
officecli validate thesis.docx
officecli view thesis.docx issues --limit 50
officecli view thesis.docx text --max-lines 120
officecli view thesis.docx html
officecli watch thesis.docx
```

## 使用建议

- 普通检查优先用 `validate`、`view issues`、`view text`。
- 需要人工看版式时，用 `view html` 或 `watch`。
- 不确定命令参数时，先运行 `officecli help`，不要猜。
- 修改正式终稿前先备份或使用 Git 管理版本。
