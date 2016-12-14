
// MIN_SEGMENTS -- минимальное число сегментов, которые будут храниться в узле
#define MIN_SEGMENTS 5

// Описание точки
typedef struct _point
{
    double x, y;
} Point;

// Описание сегмента
typedef struct _segment
{
    int p1, p2;
} Segment;


// Описание узла AABB дерева
typedef struct _AABB_node
{
    // lb -- нижняя левая точка AABB  -- left bottom
    // rt -- верхняя правая точка AABB  --  right top
    Point lb, rt;
    // segments -- массив из сегментов, приналежащих этому узлу
    int number_of_segments;
    Segment * segments;
    
    // указатели на детей
    struct AABB_node_ * ch0;
    struct AABB_node_ * ch1;
} AABB_node;



// Функция, которая создаёт дерево по сегментам
// Point * points -- массив из точек
// int number_of_points  -- число точек
//
// root->segments -- массив размера number_of_segments
// 		в нем хранятся все сегменты, а в каждом сегменте -- индексы точек массива points
// 		Например, если segments[0].p1 = 12, segments[0].p2 = 15
//		то это означает, что первый сегмент, соединяет точки points[12] и points[15]
AABB_node * make_AABB_tree(Point * points, int number_of_points)
{
	// 1) Выделяем память под корень дерева
    AABB_node * root = (AABB_node *) malloc(sizeof(AABB_node));
    // 2) Задаём значения узла
    root->number_of_segments = number_of_points - 1;
    // 3) будем хранить в каждом узле все сегменты, которые охватывает этот узел
    root->segments = (int *)malloc(root->number_of_segments * sizeof(int));
    for (int i = 0; i < root->number_of_segments; i++)
    {
        root->segments[i] = i;
        root->segments[i] = i + 1;
    }

    // Находим lb и rt  -- левую нижнюю и правую верхюю границы
    Point min = points[root->segments[0]];
    Point max = points[root->segments[0]];
    for (int i = 0; i < root->number_of_segments; i++)
    {
        for (int j = 0; j < 2; j++)
        {
           Point p;
           if ( j == 0 )
           		p = points[segments[i].p1]
           else
           		p = points[segments[i].p2]

           if (min.x > p.x) min.x = p.x;
           if (min.y > p.y) min.y = p.y;

           if (max.x < p.x) max.x = p.x;
           if (max.y < p.y) max.y = p.y;
        }
    }
    root->lb = min;
    root->rt = max;

    // Создаём остальные узлы рекурсивно
    recursive_make_AABB_tree(root);

    return root;
}


void recursive_make_AABB_tree(AABB_node * AABBt)
{
    // Создавать ли ещё детей?
    if (AABBt->number_of_segments > MIN_SEGMENTS)
    {
        // Сортируем грани по одной из координат
        // Причём координату (x, y) выбираем ту, по которой длина текущего AABB больше
        if (AABBt->rt.x - AABBt->lb.x >= AABBt->rt.y - AABBt->lb.y)
        {
            // TODO:  Сортируем массив AABBt->local_segments по x координате центра сегмента

            // |||||||||||||||||||||||||||||||||||||||||||||||||||||
        }
        else
        {
        	// TODO:  Сортируем массив AABBt->local_segments по y координате центра сегмента

            // |||||||||||||||||||||||||||||||||||||||||||||||||||||
        }

        // Первый ребёнок: ch0
        // Находим минимальную и максимальную точки в первой половине отсортированного массива граней (i от 0 до AABBt->number_of_segments/2)
        Point min = points[segments[3*AABBt->local_segments[0]+0]];
        Point max = points[segments[3*AABBt->local_segments[0]+0]];
        for (int i = 0; i < AABBt->number_of_segments/2; i++)
        {
            for (int j = 0; j < 3; j++)
            {
               Point & p = points[segments[3*AABBt->local_segments[i]+j]];
               if (min.x > p.x) min.x = p.x;
               if (min.y > p.y) min.y = p.y;
               if (min.z > p.z) min.z = p.z;

               if (max.x < p.x) max.x = p.x;
               if (max.y < p.y) max.y = p.y;
               if (max.z < p.z) max.z = p.z;
            }
        }

        // Создаём 1-го ребёнка

        AABBt->ch0 = (AABB_node *) malloc(sizeof(AABB_node));
        AABBt->ch0->number_of_segments = AABBt->number_of_segments/2;
        AABBt->ch0->local_segments = new int[AABBt->ch0->number_of_segments];
        for (int i = 0; i < AABBt->number_of_segments/2; i++)
        {
            AABBt->ch0->local_segments[i] = AABBt->local_segments[i];
        }
        AABBt->ch0->lb = min;
        AABBt->ch0->rt = max;


        // Первый ребёнок: ch1
        // Находим минимальную и максимальную точки во второй половине отсортированного массива граней (i от AABBt->number_of_segments/2 до AABBt->number_of_segments)
        min = points[segments[3*AABBt->local_segments[AABBt->number_of_segments/2]+0]];
        max = points[segments[3*AABBt->local_segments[AABBt->number_of_segments/2]+0]];
        for (int i = AABBt->number_of_segments/2; i < AABBt->number_of_segments; i++)
        {
            for (int j = 0; j < 3; j++)
            {
               Point & p = points[segments[3*AABBt->local_segments[i]+j]];
               if (min.x > p.x) min.x = p.x;
               if (min.y > p.y) min.y = p.y;
               if (min.z > p.z) min.z = p.z;

               if (max.x < p.x) max.x = p.x;
               if (max.y < p.y) max.y = p.y;
               if (max.z < p.z) max.z = p.z;
            }
        }
        // Создаём 2-го ребёнка
        // В C нужно пользоваться malloc вместо new
        AABBt->ch1 = (AABB_node *) malloc(sizeof(AABB_node));
        AABBt->ch1->number_of_segments = AABBt->number_of_segments - AABBt->number_of_segments/2;
        AABBt->ch1->local_segments = new int[AABBt->ch1->number_of_segments];
        for (int i = AABBt->number_of_segments/2; i < AABBt->number_of_segments; i++)
        {
            AABBt->ch1->local_segments[i - AABBt->number_of_segments/2] = AABBt->local_segments[i];
        }
        AABBt->ch1->lb = min;
        AABBt->ch1->rt = max;


        // Теперь, когда мы переписали все сегменты из родителя в детей, то в родителе сегменты можно не хранить
        free(AABBt->local_segments);


        // Создаём детей 1-го ребёнка
        recursive_make_AABB_tree(AABBt->ch0);
        // Создаём детей 2-го ребёнка
        recursive_make_AABB_tree(AABBt->ch1);
    }
    else
    {
        // Иначе приравниваем указатели нулю
        AABBt->ch0 = AABBt->ch1 = NULL;
    }
}


void delete_AABB_tree(AABB_node * node)
{
    // TODO:  Удаление AABB дерева

    // |||||||||||||||||||||||||||||||||||||||||||||||||||||
}


// Проверяем пересекаются ли AABB соответствующие узлам дерева n1 и n2
// n1 и n2 могут быть любыми узлами, принадлежащими любому дереву
bool check_collision(AABB_node * n1, AABB_node * n2)
{
    Point n1l = n1->lb;
    Point n1r = n1->rt;
    Point n2l = n2->lb;
    Point n2r = n2->lt;
    return !(n1l.x > n2r.x || n2l.x > n1r.x
          || n1l.y > n2r.y || n2l.y > n1r.y);
}

// Проверка столкновения 2-х объектов
// n1, n2 -- AABB деревья, соответствующие 1-му и 2-му объекту
int check_collision_AABB(AABB_node * n1, AABB_node * n2)
{
    // Если пересекаются AABB
    if (check_collision(n1, n2))
    {
         // TODO:

    }
}



// Проверка столкновения 2-х объектов
// n1, n2 -- AABB деревья, соответствующие 1-му и 2-му объекту
// collisions -- список из всех точкек пересечения
void find_collision_points(AABB_node * n1, AABB_node * n2, List * collisions)
{
    // Если пересекаются AABB
    if (check_collision(n1, n2))
    {
         // TODO:

    }
}
