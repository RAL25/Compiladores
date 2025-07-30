# Instruções LAB3 - Como executar o analisador semântico

## Compilação do arquivo binário parser

Execute o seguinte comando no diretório raiz do projeto:
```
g++ -O3 src/*.cpp src/src-ada/*.cpp -o bin/parser
```
Vai ser criado o arquivo binário/executável na pasta bin do projeto.

## Execução

OBS: Criei alguns exemplos em ada que estão na pasta "codes" e transformei em tokens usando o arquivo .jj da pasta Lexica e joguei para a pasta ins. São 4 exemplos nomeados de e1 a e4, todos implementam uma função com retorno por isso o escopo function.

Para executar o arquivo binário parser, use o seguinte comando:
```
> cd ada
> ../bin/parser < ins/e1.in
```
(Para testar os outros exemplos, troque apenas o número)