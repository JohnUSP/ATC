
# Desafio Técnico – Consulta de Restaurantes em Horário de Funcionamento

Este projeto consiste em uma aplicação em C++ com interface QML utilizando Qt 5.15.2+.

-------------------------------------------------------------------------------------------

## Tecnologias utilizadas

- Qt 5.15.2 (C++ e QML)
- QML para a interface gráfica
- QTest para testes unitários
- Git para versionamento

-------------------------------------------------------------------------------------------

## Objetivo

Criar uma aplicação que:
- Leia um arquivo CSV contendo horários de funcionamento de restaurantes
- Permita ao usuário informar um horário (HH:MM)
- Mostre uma lista de restaurantes que estão abertos nesse horário

-------------------------------------------------------------------------------------------

## Estrutura 
├── data/                      # Arquivo de entrada
│   ├── restaurant-hours.csv
├── src/                       # Código-fonte principal
│   ├── main.cpp
│   ├── main.qml
│   ├── restaurantManager.cpp
│   ├── restaurantManager.h
├── test/                       # Testes unitários
│   ├── test_restaurantManager.cpp
│   ├── test_restaurantManager.pro
│   └── restaurant-hours.csv
├── restaurantManager.pro         # Arquivo principal do Qt
└── README.md               # Este arquivo

-------------------------------------------------------------------------------------------

## Como rodar o projeto

### Requisitos

- Qt 5.15.2 instalado (compilado com suporte a QML e Quick)
- `qmake` e `make` disponíveis no sistema

### Compilando e executando o projeto

# A partir da raiz do projeto

```bash
~/Qt5.15.2/bin/qmake
make
./restaurantManager 
```
-------------------------------------------------------------------------------------------

## Como rodar os testes 

### A partir da pasta test

```bash
~/Qt5.15.2/bin/qmake
make
./test_restaurantManager 
```

-------------------------------------------------------------------------------------------

# Autor
- Desenvolvido por Johnnier Pérez Armand como parte do processo seletivo da Aditum.
- e-mal: johnnier0490@gmail.com

