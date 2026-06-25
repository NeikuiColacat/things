# DOCX/PDF 终稿检查清单

## 文档结构

- 封面
- 独创性声明和使用授权说明
- 中文摘要与关键词
- English Abstract and Key words
- 目录
- 正文
- 谢辞
- 参考文献
- 附录或外文翻译材料

## Word 检查

- 目录是自动目录，并且更新到最终页码。
- 一级、二级、三级标题层级正确。
- 每章是否按学校要求另起页。
- 图题在图下方，表题在表上方。
- 图号、表号按章节编号。
- 公式编号和正文引用一致。
- 页眉页码从正文开始符合要求。
- 参考文献编号和正文引用顺序一致。
- 封面、声明、摘要、目录、正文之间的分节不要被随手重建破坏。
- 小修优先补丁当前终稿 DOCX；只有正文结构大改或 DOCX 损坏时才全量重建。

## PDF 检查

必须导出 PDF 后逐页看：

- 是否有空白页。
- 图片是否遮挡文字。
- 表格是否超出版心。
- 公式是否被截断。
- 页眉页脚是否混乱。
- 目录页码是否正确。
- 字体是否缺字、乱码或显示方框。

推荐命令：

```bash
libreoffice --headless --convert-to pdf --outdir /tmp thesis.docx
pdfinfo /tmp/thesis.pdf
pdftotext -layout /tmp/thesis.pdf /tmp/thesis-layout.txt
```

如果使用 `officecli`：

```bash
officecli validate thesis.docx
officecli view thesis.docx issues --limit 50
officecli view thesis.docx text --max-lines 80
```

更多常见坑见 `guet-word-layout-pitfalls.md`。

## 不要提交的内容

- Agent 对话记录。
- 临时检查报告。
- 缓存目录。
- 未使用的大数据文件。
- 模型权重或大型中间文件，除非学院明确要求。
- 带有本地绝对路径的截图或说明。
