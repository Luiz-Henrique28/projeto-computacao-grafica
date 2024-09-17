#include <GL/glut.h>

GLint WINDOW_WIDTH = 500, WINDOW_HEIGHT = 500;

void initializeGlut(int argc, char *argv[]){
    //Inicializa a biblioteca GLUT e negocia uma 
    //seção com o sistema de janelas
    glutInit(&argc, argv);

    //Define qual será o modo inicial de display
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    //Definir a posição inicial da janela, passando 
    //canto superior esquerdp
    glutInitWindowPosition(100,100);

    //Define a largura e altura da janela
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);

    //Cria a janela, passando o titulo
    glutCreateWindow("Meu primeiro programa OpenGL");
}

void initialize(){
    //Define a cor de fundo
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    
    //Matriz que usaremos para opperacoes
    glMatrixMode(GL_MODELVIEW);

    //erquerdo, direito, baixo, cima
    gluOrtho2D(0, WINDOW_WIDTH, WINDOW_HEIGHT, 0);
}
void drawPoint(GLfloat x, GLfloat y){
    glBegin(GL_POINTS);
        glVertex2f(x, y);
    glEnd();
    glFlush();
}

void draw(){
    glClear(GL_COLOR_BUFFER_BIT);

    glPointSize(5.0);
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
        glVertex2f(10.0, 10.0);
        glVertex2f(100.0, 10.0);
    glEnd();

    glFlush();
}

void handle_mouse(GLint button, GLint action, GLint x, GLint y){
    if(button == GLUT_LEFT_BUTTON && action == GLUT_DOWN){
        drawPoint(x, y);
    }
}

int main(int argc, char *argv[])
{   
    initializeGlut(argc, argv);
    initialize();
    glutDisplayFunc(draw);
    glutMouseFunc(handle_mouse);
    glutMainLoop();
    
    return EXIT_SUCCESS;
}
