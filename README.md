# ⛏️ Mina Ferro Pelado — Sistema de Gestão de Pedidos

Sistema de linha de comando desenvolvido em **C** para gerenciar pedidos de minério de ferro classificados por grau de pureza, calculando faturamento, lucro e estatísticas por categoria.

> Projeto desenvolvido como exercício prático de lógica de programação em C, com foco em estruturas de dados, loops e cálculos financeiros.

---

## 📋 Funcionalidades

- Cadastro de valores por grau de pureza (Alto, Médio Nacional, Médio Internacional, Médio e Baixo)
- Registro de 12 pedidos com quantidade em toneladas por grau
- Cálculo automático de:
  - Faturamento por grau e total
  - Lucro descontando custo de mão de obra (R$ 106,96/tonelada)
  - Grau com maior receita gerada
  - Grau com maior volume extraído (toneladas)
- Relatório final completo no terminal

---

## 🗂️ Graus de Pureza

| Grau                    | Teor mínimo de ferro |
|-------------------------|----------------------|
| Alto Grau               | ≥ 95%                |
| Grau Médio Nacional     | ≥ 85%                |
| Grau Médio Internacional| ≥ 80%                |
| Grau Médio              | ≥ 75%                |
| Grau Baixo              | < 75%                |

---

## 🚀 Como executar

### Pré-requisitos

- Compilador C (GCC recomendado)
- Terminal (Linux, macOS ou Windows com MinGW/WSL)

### Compilar e rodar

```bash
# Clone o repositório
git clone https://github.com/seu-usuario/mina-ferro-pelado.git
cd mina-ferro-pelado

# Compile
gcc -o mina main.c

# Execute
./mina
```

> No Windows: `gcc -o mina.exe main.c` e depois `mina.exe`

---

## 📁 Estrutura do projeto

```
mina-ferro-pelado/
├── main.c          # Código-fonte principal
├── README.md       # Documentação do projeto
└── .gitignore      # Arquivos ignorados pelo Git
```

---

## 🧠 Conceitos aplicados

- Arrays e variáveis em C
- Estruturas de repetição (`for`, `do...while`)
- Entrada e saída formatada (`printf` / `scanf`)
- Acumuladores e comparações numéricas
- Constantes com `#define`

---

## 📌 Melhorias planejadas

- [ ] Refatorar em funções (modularização)
- [ ] Adicionar struct `Grau` para eliminar repetição de código
- [ ] Implementar validação de entrada do usuário
- [ ] Exportar relatório para arquivo `.txt`
- [ ] Versão com interface gráfica (ncurses ou GTK)

---

## 👤 Autor

Filipe Roberto Fernandes de Oliveira 
[![LinkedIn](https://img.shields.io/badge/LinkedIn-blue?style=flat&logo=linkedin)](https://www.linkedin.com/in/filiperobertofernandes/?locale=en-US)
[![GitHub](https://img.shields.io/badge/GitHub-black?style=flat&logo=github)](https://github.com/mrfiliperoberto)

---

## 📄 Licença

Este projeto está sob a licença MIT. Veja o arquivo [LICENSE](LICENSE) para mais detalhes.
