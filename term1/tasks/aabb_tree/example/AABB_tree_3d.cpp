typedef struct point
{
    double x, y, z;
} Point;



typedef struct AABB_node_
{
    // left_b -- нижняя левая точка AABB
    // right_b -- верхняя правая точка AABB
    Point left_b, right_b;
    // faces -- массив из граней
    int * faces;
    int number_of_faces;
    // указатели на детей
    struct AABB_node_ * ch0;
    struct AABB_node_ * ch1;
} AABB_node;


void make_AABB_tree_from_root()
{
    // В C++ вместо malloc и free принято использовать new и delete
    // Строка ниже это почти то же самое, что и: AABB_node * root = (AABB_node *) malloc(sizeof(AABB_node));
    AABB_node * root = new AABB_node();
    // Задаём значения узла
    root->number_of_faces = get_number_of_faces();
    root->faces = new int[root->number_of_faces];
    for (int i = 0; i < root->number_of_faces; i++)
    {
        root->faces[i] = i;
    }

    // Находим left_b и right_b
    Point min(points[indices[3*root->faces[0]+0]]);
    Point max(points[indices[3*root->faces[0]+0]]);
    for (int i = 0; i < root->number_of_faces; i++)
    {
        for (int j = 0; j < 3; j++)
        {
           Point & p = points[indices[3*root->faces[i]+j]];
           if (min.x > p.x) min.x = p.x;
           if (min.y > p.y) min.y = p.y;
           if (min.z > p.z) min.z = p.z;

           if (max.x < p.x) max.x = p.x;
           if (max.y < p.y) max.y = p.y;
           if (max.z < p.z) max.z = p.z;
        }
    }
    root->left_b = min;
    root->right_b = max;

    // сохраняем созданный узел во внешней переменной AABB_tree
    AABB_tree = root;
    // Создаём остальные узлы рекурсивно
    make_AABB_tree(root);
}


void make_AABB_tree(AABB_node * AABBt)
{
    // Создавать ли ещё детей?
    if (AABBt->number_of_faces > 1)
    {
        // Сортируем грани по одной из координат
        // Причём координату (x, y или z) выбираем ту, по которой длина текущего AABB больше
        if (AABBt->right_b.x - AABBt->left_b.x >= AABBt->right_b.y - AABBt->left_b.y &&
            AABBt->right_b.x - AABBt->left_b.x >= AABBt->right_b.z - AABBt->left_b.z)
        {
            std::sort(AABBt->faces, AABBt->faces + AABBt->number_of_faces, [this](int i, int j) { return this->dual_points[i].x < this->dual_points[j].x; });
        }
        else if (AABBt->right_b.y - AABBt->left_b.y >= AABBt->right_b.x - AABBt->left_b.x &&
                 AABBt->right_b.y - AABBt->left_b.y >= AABBt->right_b.z - AABBt->left_b.z)
        {
            std::sort(AABBt->faces, AABBt->faces + AABBt->number_of_faces, [this](int i, int j) { return this->dual_points[i].y < this->dual_points[j].y; });
        }
        else if (AABBt->right_b.z - AABBt->left_b.z >= AABBt->right_b.x - AABBt->left_b.x &&
                 AABBt->right_b.z - AABBt->left_b.z >= AABBt->right_b.y - AABBt->left_b.y)
        {
            std::sort(AABBt->faces, AABBt->faces + AABBt->number_of_faces, [this](int i, int j) { return this->dual_points[i].z < this->dual_points[j].z; });
        }

        // Первый ребёнок: ch0
        // Находим минимальную и максимальную точки в первой половине отсортированного массива граней (i от 0 до AABBt->number_of_faces/2)
        Point min = points[indices[3*AABBt->faces[0]+0]];
        Point max = points[indices[3*AABBt->faces[0]+0]];
        for (int i = 0; i < AABBt->number_of_faces/2; i++)
        {
            for (int j = 0; j < 3; j++)
            {
               Point & p = points[indices[3*AABBt->faces[i]+j]];
               if (min.x > p.x) min.x = p.x;
               if (min.y > p.y) min.y = p.y;
               if (min.z > p.z) min.z = p.z;

               if (max.x < p.x) max.x = p.x;
               if (max.y < p.y) max.y = p.y;
               if (max.z < p.z) max.z = p.z;
            }
        }
        // Создаём 1-го ребёнка
        // В C нужно пользоваться malloc вместо new
        AABBt->ch0 = new AABB_node();
        AABBt->ch0->number_of_faces = AABBt->number_of_faces/2;
        AABBt->ch0->faces = new int[AABBt->ch0->number_of_faces];
        for (int i = 0; i < AABBt->number_of_faces/2; i++)
        {
            AABBt->ch0->faces[i] = AABBt->faces[i];
        }
        AABBt->ch0->left_b = min;
        AABBt->ch0->right_b = max;


        // Первый ребёнок: ch1
        // Находим минимальную и максимальную точки во второй половине отсортированного массива граней (i от AABBt->number_of_faces/2 до AABBt->number_of_faces)
        min = points[indices[3*AABBt->faces[AABBt->number_of_faces/2]+0]];
        max = points[indices[3*AABBt->faces[AABBt->number_of_faces/2]+0]];
        for (int i = AABBt->number_of_faces/2; i < AABBt->number_of_faces; i++)
        {
            for (int j = 0; j < 3; j++)
            {
               Point & p = points[indices[3*AABBt->faces[i]+j]];
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
        AABBt->ch1 = new AABB_node();
        AABBt->ch1->number_of_faces = AABBt->number_of_faces - AABBt->number_of_faces/2;
        AABBt->ch1->faces = new int[AABBt->ch1->number_of_faces];
        for (int i = AABBt->number_of_faces/2; i < AABBt->number_of_faces; i++)
        {
            AABBt->ch1->faces[i - AABBt->number_of_faces/2] = AABBt->faces[i];
        }
        AABBt->ch1->left_b = min;
        AABBt->ch1->right_b = max;

        delete [] AABBt->faces;


        // Создаём детей 1-го ребёнка
        make_AABB_tree(AABBt->ch0);
        // Создаём детей 2-го ребёнка
        make_AABB_tree(AABBt->ch1);
    }
    else
    {
        // Иначе приравниваем указатели нулю
        // В C -- NULL вместо nullptr
        AABBt->ch0 = AABBt->ch1 = nullptr;
    }
}


void delete_AABB_tree(AABB_node * node)
{
    // В конце программы дерево нужно обязательно удалить
    // В C -- вместо delete и delete[] используется free()
    if (node->ch0 == nullptr)
    {
        delete [] node->faces;
        delete node;
    }
    else
    {
        delete_AABB_tree(node->ch0);
        delete_AABB_tree(node->ch1);
    }
}


// Проверяем пересекаются ли AABB соответствующие узлам дерева n1 и n2
// n1 и n2 могут быть любыми узлами, принадлежащими любому дереву
bool check_collision(AABB_node * n1, AABB_node * n2)
{
    Point n1l = n1->left_b;
    Point n1r = n1->right_b;
    Point n2l = n2->left_b;
    Point n2r = n2->right_b;
    return !(n1l.x > n2r.x || n2l.x > n1r.x
          || n1l.y > n2r.y || n2l.y > n1r.y
          || n1l.z > n2r.z || n2l.z > n1r.z);
}

// Проверка столкновения 2-х объектов
// n1, n2 -- AABB деревья, соответствующие 1-му и 2-му объекту
// collisions -- List из всех пересекающихся граней (в 2d в нём можно хранить, например, точки пересечения)
void find_collision_triangles(AABB_node * n1, AABB_node * n2, List * collisions)
{
    // Если пересекаются AABB
    if (check_collision(n1, n2))
    {
        // Если у текущих узлов нет детей
        if (n1->ch0 == nullptr && n2->ch0 == nullptr)
        {
            // Находим пересечения
            for (int i = 0; i < n1->number_of_faces; i++)
            {
                for (int j = 0; j < n2->number_of_faces; j++)
                {
                    if (check_collision_faces(n1->faces[i], n2->faces[j]))
                    {
                        insert_back(collisions, indices[3*n1->faces[i]]);
                        insert_back(collisions, indices[3*n1->faces[i]+1]);
                        insert_back(collisions, indices[3*n1->faces[i]+2]);
                    }
                }
            }
        }
        // Если дети есть хотя бы у одного узла то рекурсивно ищем пересечения детей этих узлов
        else if (n1->ch0 == nullptr)
        {
            find_collision_triangles(n1, n2->ch0, collisions);
            find_collision_triangles(n1, n2->ch1, collisions);
        }
        else if (n2->ch0 == nullptr)
        {
            find_collision_triangles(n1->ch0, n2, collisions);
            find_collision_triangles(n1->ch1, n2, collisions);
        }
        else
        {
            find_collision_triangles(n1->ch0, n2->ch0, collisions);
            find_collision_triangles(n1->ch0, n2->ch1, collisions);
            find_collision_triangles(n1->ch1, n2->ch0, collisions);
            find_collision_triangles(n1->ch1, n2->ch1, collisions);
        }
    }
}
