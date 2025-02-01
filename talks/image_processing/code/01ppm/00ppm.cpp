/*
    Формат .ppm

    Формат хранения изображения .ppm это один из самых простейших форматов.
    Например, изображение 3 на 2 пикселя из предыдущих примеров можно представить в формате .ppm 
    как текстовый файл содержащий следующее:

        P3
        3 2
        255
        109  53  35
        116  116 94
        52  72  49
        40  41  95
        43  124  53
        58  34  60

    
    Формат файла имеет следующий вид:

        1)  P3: означает что это файл формата .ppm. Всего есть 6 вариантов формата .ppm:

                P1: На каждый пиксель приходится 1 бит   информации (0 = черный цвет, 1 = белый)
                P2: На каждый пиксель приходится 1 байт  информации (черно-белая картинка)
                P3: На каждый пиксель приходится 3 байта информации (цветная картинка)
                P4: То же самое, что и P1, но в бинарном формате
                P5: То же самое, что и P2, но в бинарном формате
                P6: То же самое, что и P3, но в бинарном формате
                
        2)  3 2: размеры изображения
        3)  255: максимальное значение компоненты цвета
        4)  дальше идут компоненты цветов всех пикселей

    
    Задачи:
    
        1)  Это изображение хранится в файле tiny.ppm. 
            Откройте файл tiny.ppm с помощью текстового редактора и убедитесь в этом.

        2)  Не каждое приложение для просмотра и работы с изображениями поддерживает формат .ppm.
            Для просмотра изображений данного формата советую приложение IrfanView.
            Откройте файл tiny.ppm в приложении IrfanView и убедитесь, что картинка отображается правильно.
            При приближении маленькая картинка в IrfanView может оказаться размытой.
            Чтобы отключить размытие уберите галочку в View -> Display Options -> Use Resample for zooming и приблизьте картинку.
*/

int main(){}