# 📚 Implementación de Árbol AVL para Ranking Académico
Curso: Programación III

## Introducción
Como parte de mi aprendizaje sobre estructuras de datos avanzadas, este proyecto presenta una solución para organizar el ranking académico de estudiantes. He seleccionado el Árbol AVL porque, a diferencia de un árbol de búsqueda simple, este se mantiene equilibrado automáticamente, lo que nos asegura que el programa sea siempre rápido incluso con muchos datos.

## ¿Qué hace este programa? 🛠️
El sistema permite gestionar la información de los estudiantes (ID, nombre, carrera y su skill score) bajo las siguientes reglas que he implementado:

Ordenamiento Dinámico: El árbol se organiza por el skill_score.

Criterio de Desempate: Si dos compañeros tienen el mismo puntaje, el código utiliza el student_id para decidir la posición.

Ranking Real: Mediante un recorrido InOrden, el programa genera una lista del estudiante con mayor puntaje al menor.

## Reflexión Técnica 🧠
Durante el desarrollo, pude notar que la ventaja del AVL sobre un árbol normal (BST) es fundamental para un ranking. Si insertamos estudiantes con scores ya ordenados en un árbol normal, este se volvería una línea recta y perdería eficiencia. El AVL, mediante sus rotaciones, nos garantiza que la altura se mantenga mínima, optimizando las búsquedas.

## Información del Autor 🪪
Nombre: Erix Alejandro Solares Flores

Carnet: 9941-20-23978

Carrera: Ingeniería en Sistemas
