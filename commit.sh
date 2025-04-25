#!/bin/bash

echo ""
echo "📁 Commitando em: $(pwd)"
echo ""

echo "Selecione a categoria do commit:"
echo "1 - BeeCrowd"
echo "2 - CodeForces"
echo "3 - AG"
echo "4 - LeetCode"
echo "5 - Docs"
echo ""

read -p "Digite o número correspondente: " tipo

case $tipo in
  1) prefixo="BeeCrowd" ;;
  2) prefixo="CodeForces" ;;
  3) prefixo="AG" ;;
  4) prefixo="LeetCode" ;;
  5) prefixo="Docs" ;;
  *) echo "❌ Tipo inválido"; exit 1 ;;
esac

echo ""
read -p "Mensagem do commit: " msg

if [ -z "$msg" ]; then
  echo "❌ A mensagem do commit não pode estar vazia."
  exit 1
fi

echo ""
echo "🚀 Comitando com: $prefixo: $msg"
echo ""

git add .
git commit -m "$prefixo: $msg" || {
  echo "❌ Erro ao tentar commitar. Verifique se há validações ou hooks ativos."
  exit 1
}

git push && echo "✅ Push feito com sucesso!"
