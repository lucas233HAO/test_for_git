#include "multimedia.h"
#include "photo.h"
#include "video.h"
#include "film.h"
#include "group.h"
#include "generaltable.h"
#include "myserver.h"
#include <memory>
#include <iostream>
using namespace std;

//#define TEST_Q4
//#define TEST_Q6
//#define TEST_Q9
//#define TEST_Q10
//#define TEST_INIT_SERVER_TABLE
//#define TEST_START_SERVER_WITH_TABLE
//#define TEST_RETURN_PARA
//#define TEST_TABLE_RETURN_PARA
#define TEST_SERVER_ALL_FONCTION


#ifdef TEST_Q4
/**
 * @brief playMultimedia
 * @param tab the multimedia table that we want to play
 * @param count the numer of the multimedia object
 */
void playMultimedia(Multimedia **tab, unsigned int count)
{
    for(unsigned int i=0;i<count;i++)
    {
        tab[i]->display(cout);
    }
}
#endif

/**
 * @brief main the main function
 * @param argc
 * @param argv
 * @return 0
 */
int main(int argc, const char* argv[])
{
    #ifdef TEST_Q4
    Multimedia **m = new Multimedia*- [3]
    m[0] = new Photo("abc","123");
    m[1] = new Video("def","456");
    m[2] = new Photo("ghi","789");
    playMultimedia(m,3);
    #endif

    #ifdef TEST_Q6
    Film *f = new Film("asc","256");
    f->display(cout);
    int a[5] = {1,6,2,5,2};
    f->setChapiter(a,5);
    f->display(cout);
    int b[8] = {3,5,2};
    f->setChapiter(b,3);
    f->display(cout);
    #endif

    #ifdef TEST_Q9
    Group *g1 = new Group();
    Group *g2 = new Group();
    MPtr p1(new Photo("abc","123"));  // first pointeurs to "abc"
    MPtr p2(new Photo("def","456"));
    MPtr f1 (new Film("frg","962"));
    MPtr f2 (new Film("lmk","547"));
    MPtr v1(nullptr);
    g->creatPhoto("Phoenix.jpg","Phoenix.jpg");
    g1->push_back(p1);       // second poiter to "abc"
    g1->push_back(p2);
    g1->push_back(f1);
    g2->push_back(f1);      //third pointer to "abc"
    g2->push_back(f2);
    g2->push_back(p1);
    g1->showMember();
    printf("\n");
    g2->showMember();#ifdef TEST_START_SERVER_WITH_TABLE
    printf("\n \n");
    g1->begin()->reset();
    auto it = g2-> begin();  // begin() est un pointeur qui pointe vers le premier element dans la liste.Pour les éléments suivants, on peut pas y accéder directement
                             //  dans une position concrete de la liste.Donc on doit utiliser <<it>> puis avance
    std::advance(it,2);
    it->reset();
    printf("finished1 \n");
    p1.reset();
    printf(" \n finished2 ");
    #endif

    #ifdef TEST_Q10
    GeneralTable *g = new GeneralTable();
    g->creatPhoto("Phoenix.jpg","Phoenix.jpg");
    g->creatVideo("cs.mp4","cs.mp4");
    g->findMultimediaDisplay();
    g->playMultimedia("Phoenix.jpg");
    #endif

    #ifdef TEST_INIT_SERVER_TABLE
    GeneralTable *g = new GeneralTable();
    g->creatPhoto("Phoenix.jpg","Phoenix.jpg");
    g->creatVideo("cs.mp4","cs.mp4");
    MyServer *server = new MyServer(g);
    server->findPlayMultimedia("Phoenix.jpg");
    #endif

    #ifdef TEST_START_SERVER_WITH_TABLE
    GeneralTable *g = new GeneralTable();
    g->creatPhoto("Phoenix.jpg","Phoenix.jpg");
    g->creatVideo("cs.mp4","cs.mp4");
    MyServer *server = new MyServer(g);
    server->startServer();
    #endif

    #ifdef TEST_RETURN_PARA
    Photo *f = new Photo("asc","256");
    Video *v = new Video("rbg","739");
    string s = f->getAllParameters();
    string s1 = v->getAllParameters();
    cout<<s<<endl;
    cout<<s1<<endl;
    #endif

    #ifdef TEST_TABLE_RETURN_PARA
    GeneralTable *g = new GeneralTable();
    g->creatPhoto("Phoenix.jpg","Phoenix.jpg");
    g->creatVideo("cs.mp4","cs.mp4");
    string s = g->searcMultimediaReturnParameters("Phoenix.jpg");
    cout<<s<<endl;
    #endif

    #ifdef TEST_SERVER_ALL_FONCTION
    GeneralTable *g = new GeneralTable();
    g->creatPhoto("Phoenix.jpg","Phoenix.jpg",1920,1200);
    g->creatVideo("cs.mp4","cs.mp4",20);
    MyServer *server = new MyServer(g);
    server->startServer();
    #endif

    return 0;
}
