# Recebe um arquivo .in da saída do lab1 pela entrada padrão
# e retorna uma string de tokens para teste no site

while True:
    try:
        token = input().split()[0]
        if token != '$':
            print(token, end=' ')
        else:
            print()
    except EOFError:
        break
