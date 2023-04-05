#include <GL/glut.h>
#include <GL/freeglut.h>
#include <math.h>


// Variáveis para controlar se a seta para cima foi pressionada e se o programa deve ser iniciado
bool setaParaCima = false;
bool startProgram = false;



// Variável da posição da linha
float linha_x = 0.0;
float line_y = -0.95;


// Variáveis da bola
float bola_x = 0.0;
float bola_y = 0.0;
float velocidade_bola = 0.03;
float direcao_bola = M_PI / 4.0;
const float raio_bola = 0.05;

// Variáveis do tijolo
const int numero_tijolos = 8;
int numero_tijolos_destruidos = 0;
const float largura_tijolo = 0.2;
const float altura_tijolo = 0.1;
const float gap_tijolo = 0.02;
float posicao_tijolo[numero_tijolos];

// Variáveis de estado
bool tijolos[numero_tijolos];



// Função para desenhar a linha
void draw_line(float x) {
    // Desenha a linha
    glBegin(GL_LINES);
    glVertex2f(x - 0.09, -0.95);
    glVertex2f(x + 0.09, -0.95);
    glEnd();
}


// Função para desenhar um círculo
void draw_circle(float x, float y, float r) {
    glBegin(GL_POLYGON);
    for (int i = 0; i < 32; i++) {
        float angle = 2.0 * M_PI * (float)i / 32.0;
        float dx = r * cosf(angle);
        float dy = r * sinf(angle);
        glVertex2f(x + dx, y + dy);
    }
    glEnd();
}

// Função para desenhar um retângulo
void draw_rect(float x, float y, float w, float h) {
    glBegin(GL_QUADS);
    glVertex2f(x - w / 2.0, y - h / 2.0);
    glVertex2f(x - w / 2.0, y + h / 2.0);
    glVertex2f(x + w / 2.0, y + h / 2.0);
    glVertex2f(x + w / 2.0, y - h / 2.0);
    glEnd();
}

// Função para desenhar a cena
void display() {
    // Limpa o buffer de cores
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.2, 0.2, 0.2, 1.0);

    if (!setaParaCima) {
        // exibe a mensagem de boas-vindas na tela
        glColor3f(1.0f, 1.0f, 1.0f);
        // Define a posição do texto
    	glRasterPos2f(-0.5f, 0.8f);
        glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, (const unsigned char*)"Bem-Vindo ao Brick Breaker!");
        glRasterPos2f(-0.4f, 0.6f);
        glutBitmapString(GLUT_BITMAP_HELVETICA_18, (const unsigned char*)"Pressione a seta para cima...");
    } else if (startProgram) {
        // Desenha o jogador
	    glColor3f(0.5, 0.5, 1.0); // cor azul clara
	    draw_line(linha_x);
	
	    // Desenha a bola
	    glColor3f(1.0, 1.0, 0.0); // cor amarela
	    draw_circle(bola_x, bola_y, raio_bola);
	
	    // Desenha os tijolos
	    for (int i = 0; i < numero_tijolos; i++) {
	        if (tijolos[i]) {
	            glColor3f(0.0, 1.0, 0.0);
	            float x = -0.8 + largura_tijolo / 2.0 + i * (largura_tijolo + gap_tijolo);
	            glColor3f(1.0, 0.5, 0.5); // cor rosa clara
	            draw_rect(x, 0.8, largura_tijolo, altura_tijolo);
	        }
	    }
	    
	    // Verifica se a bola ultrapassou a linha inferior da janela
		if (bola_y - raio_bola < -1.0) {
			velocidade_bola = 0.0;
		    // acaboou
	        glClear(GL_COLOR_BUFFER_BIT);
		    glMatrixMode(GL_MODELVIEW);
		    glLoadIdentity();
		    glColor3f(1.0f, 0.0f, 0.0f);
		    glRasterPos2f(-0.3f, 0.0f);
		    glutBitmapString(GLUT_BITMAP_HELVETICA_18, (const unsigned char*)"PERDEU!!!");
		}
		
		// Verifica se todos os tijolos foram destruídos
		if (numero_tijolos_destruidos == numero_tijolos) {
			velocidade_bola = 0.0;
		    glClear(GL_COLOR_BUFFER_BIT);
		    glMatrixMode(GL_MODELVIEW);
		    glLoadIdentity();
		    glColor3f(0.0f, 1.0f, 0.0f);
		    glRasterPos2f(-0.4f, 0.0f);
		    glutBitmapString(GLUT_BITMAP_HELVETICA_18, (const unsigned char*)"VC VENCEU!!!");
		    glutSwapBuffers();
		} else {
			// Troca os buffers
	    	glutSwapBuffers();
		}
    }
    glFlush();

}

// Função para atualizar a posição do jogador
void update_player(int key, int x, int y) {

    if (GLUT_KEY_UP) { 
        setaParaCima = true;
        startProgram = true;

        
        switch (key) {
	        case GLUT_KEY_LEFT: // Seta esquerda
	            linha_x -= 0.1;
	            break;
	        case GLUT_KEY_RIGHT: // Seta direita
	            linha_x += 0.1;
	            break;
	    }
    }
	
}



// Função para atualizar a posição da bola
void update_ball() {
	
	if (startProgram == true) {
		// Move a bola
		bola_x += velocidade_bola * cosf(direcao_bola);
		bola_y += velocidade_bola * sinf(direcao_bola);
	}
	
	
	// Verifica se a bola colidiu com a linha
    
    if (bola_y - raio_bola <= line_y) {
        if (fabs(bola_x - linha_x) <= raio_bola + 0.09) {
            direcao_bola = -direcao_bola;
            bola_y = line_y + raio_bola;
        }
    }



	
	// Verifica se a bola colidiu com os tijolos
	for (int i = 0; i < numero_tijolos; i++) {
	    if (tijolos[i]) {
	        float x = -0.8 + largura_tijolo / 2.0 + i * (largura_tijolo + gap_tijolo);
	        float y = 0.8;
	        if (bola_x > x - largura_tijolo / 2.0 - raio_bola &&
	            bola_x < x + largura_tijolo / 2.0 + raio_bola &&
	            bola_y > y - altura_tijolo / 2.0 - raio_bola &&
	            bola_y < y + altura_tijolo / 2.0 + raio_bola) {
	            tijolos[i] = false;
	            numero_tijolos_destruidos++;
	            direcao_bola = -direcao_bola;
	            break;
	        }
	    }
	}
	
	// Verifica se a bola colidiu com as paredes
	if (bola_x < -1.0 + raio_bola || bola_x > 1.0 - raio_bola) {
	    direcao_bola =  M_PI - direcao_bola;
	}
	if (bola_y > 1.0 - raio_bola) {
	    direcao_bola = -direcao_bola;
	}
	
	
}


// Função para atualizar a cena
void update(int value) {
	update_ball();
	glutPostRedisplay();
	glutTimerFunc(16, update, 0);
}

// Função principal
int main(int argc, char** argv) {
	// Inicializa o GLUT
	glutInit(&argc, argv);
	// Configura o modo de display
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	
	// Configura o tamanho da janela
	glutInitWindowSize(640, 480);
	
	// Cria a janela
	glutCreateWindow("Terceira Nota");
	
	// Configura a função de desenho
	glutDisplayFunc(display);
	glutSpecialFunc(update_player);
	
	// Configura a função de atualização
	glutTimerFunc(0, update, 0);
	
	
	for (int i = 0; i < numero_tijolos; i++) {
	    tijolos[i] = true;
	}
	
	// Entra no loop de eventos
	glutMainLoop();
	
	return 0;
}



