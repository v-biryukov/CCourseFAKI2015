level = new Array();
glavs = new Array();
amount_glavs = new Array();
////////////////////////////////////////WRITE HERE////////////////////////////////////
// название электронного учебника
basefolder = "/el_books/numerical_methods/";
book_theme = 'Учебное пособие по курсу \"Численные методы в оптике\"';
// название уровней учебника
level[0] = 'Конспект лекций';
level[1] = 'Лабораторные работы';
// текущий уровень
curr_level = 0;								
// количество глав в каждом уровне   
amount_glavs[0] = 11;
amount_glavs[1] = 5;
////////////////////////////////////////STOP WRITE HERE////////////////////////////////////
for(var j = 0; j <= level.length;++j)
	glavs[j] = new Array();
for(var j = 0; j <= level.length;++j)
	for (var i = 0; i <= amount_glavs[j];++i)
		glavs[j][i] = new Array();
currglav='0';
currpage='0';
cod = currglav+'_'+currpage;
////////////////////////////////////////WRITE HERE////////////////////////////////////
/// полные пути к файлам [номер уровня][номер главы][номер параграфа]
//		level[0] 
    glavs[0][0][0] = 'main.html';
	
	glavs[0][1][0] = 'library/library.html';
	glavs[0][1][1] = 'library/fftw.html';
	glavs[0][1][2] = 'library/ublas.html';
	
	glavs[0][2][0] = 'lectures/intro.html';
	glavs[0][3][0] = 'lectures/glava1.html';
	glavs[0][4][0] = 'lectures/glava2.html';
	glavs[0][4][1] = 'lectures/glava2_1.html';
	glavs[0][4][2] = 'lectures/glava2_2.html';
	glavs[0][4][3] = 'lectures/glava2_3.html';
	glavs[0][4][4] = 'lectures/glava2_4.html';	
	glavs[0][5][0] = 'lectures/glava3.html';
	glavs[0][6][0] = 'lectures/glava4.html';
	glavs[0][6][1] = 'lectures/glava4_1.html';
	glavs[0][6][2] = 'lectures/glava4_2.html';
	glavs[0][6][3] = 'lectures/glava4_3.html';	
	glavs[0][7][0] = 'lectures/glava5.html';
	glavs[0][8][0] = 'lectures/glava6.html';
	glavs[0][9][0] = 'lectures/glava7.html';
	glavs[0][10][0] = 'lectures/glava8.html';
	glavs[0][11][0] = 'lectures/program_for_exam.html';
	
	
//		level[1] 
	glavs[1][0][0] = 'main_lab.html';

	glavs[1][1][0] = 'lab/lab_1.html';
	glavs[1][1][1] = 'lab/lab_1_1.html';
	glavs[1][1][2] = 'lab/lab_1_2.html';
	glavs[1][1][3] = 'lab/lab_1_3.html';
	glavs[1][1][4] = 'lab/lab_1_4.html';

	glavs[1][2][0] = 'lab/lab_2.html';
	glavs[1][2][1] = 'lab/lab_2_1.html';
	glavs[1][2][2] = 'lab/lab_2_2.html';
	glavs[1][2][3] = 'lab/lab_2_3.html';
	glavs[1][2][4] = 'lab/lab_2_4.html';
	glavs[1][2][5] = 'lab/lab_2_5.html';	


    glavs[1][3][0] = 'lab/lab_3.html';
	glavs[1][3][1] = 'lab/lab_3_1.html';
	glavs[1][3][2] = 'lab/lab_3_2.html';
	glavs[1][3][3] = 'lab/lab_3_3.html';
	glavs[1][3][4] = 'lab/lab_3_4.html';
	
    glavs[1][4][0] = 'lab/lab_4.html';
	glavs[1][4][1] = 'lab/lab_4_1.html';
	glavs[1][4][2] = 'lab/lab_4_2.html';
	
    glavs[1][5][0] = 'lab/lab_5.html';
	glavs[1][5][1] = 'lab/lab_5_1.html';
	glavs[1][5][2] = 'lab/lab_5_2.html';
	glavs[1][5][3] = 'lab/lab_5_3.html';	
	glavs[1][5][4] = 'lab/lab_5_4.html';	
	
////////////////////////////////////////STOP WRITE HERE////////////////////////////////////