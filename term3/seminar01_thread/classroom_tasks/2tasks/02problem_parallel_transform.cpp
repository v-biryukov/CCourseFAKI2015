/*
    Задача:


        Напишите шаблонную функцию parallelTransform, аналог функции std::transform
        из библиотеки algorithm.
        Количество потоков в этот раз не передавайте через аргументы функции, а узнайте
        внутри самой функции с помощью std::thread::hardware_concurrency().
*/