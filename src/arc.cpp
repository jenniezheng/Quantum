#include "arc.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;



Arc::Arc(int num){
    switch(num){
    case 1: createArcOne(); break;
    case 2: createArcTwo(); break;
    case 3: createArcThree(); break;
    }
}

void Arc::cleanUp(){
    for(unsigned i=0; i<m_pages.size(); i++)
        delete m_pages[i];
}

void Arc::createArcOne() {
  Page* n1_1=new Page("Highschool. I met the girl of my dreams as I ran through the park, not\
 realizing it until after I had flown past her.");
  Page* n1_1b=new Page("I kept running and didn't turn back; I never saw her again.");
  Page* n1_2=new Page("I turned back and confessed my attraction; we stumbled awkwardly at\
 first but then hit it off! A week later, we've started dating. She says she wants a committed relationship.");
  Page* n1_2b=new Page("I tell her I'm not ready yet. She confesses her strong feelings for\
 me and asks if I might change my mind after some time.");
  Page* n1_2c=new Page("I tell her I don't want to stay with her in the long run. Tears\
 form in her eyes and we lost contact after that day. I never see her again.");
  Page* n1_3=new Page("I tell her I want us to have a steady relationship. She is\
 ecstatic, leaping into my arms with joy.");
  Page* n2_1=new Page("We've been dating for one year; it has been almost perfect until\
 one day, she notices me admiring another girl.");               

  n1_1->addOption("I keep running.", n1_1b);
  n1_1->addOption("I turn back and strike a conversation.", n1_2);
  n1_1b->addOption("Return to beginning.",n1_1);
  n1_2->addOption("I am ready for that.", n1_3);
  n1_2->addOption("It's too soon.", n1_2b);
  n1_2b->addOption("I want us to have more meaning.", n1_3);
  n1_2b->addOption("This is just a splash in the pan.", n1_2c);
  n1_2c->addOption("Return to beginning.",n1_1);
  n1_3->addOption("How long will we last? Only time will tell.", n2_1);

  Page* n2_1b=new Page("I tell her she's overreacting, but she pulls away, tears streaming.");
  Page* n2_1d=new Page("I leave her alone and she steadily becomes more withdrawn as the\
 days pass. Eventually she stops talking to me altogether and we can't\
 take it anymore. We part ways.");
  Page* n2_2=new Page("I lose some of her trust but we pull back together. Eventually we\
 graduate high school together but are attending separate colleges. Year 2. We\
 confess our fears that we won't work out long distance.");
  Page* n2_2b=new Page("We admit that the odds are stacked against us and that it would be\
 better to end the relationship sooner rather than later. We go our\
 separate ways and as our daily communication dwindles, we forget what used to be.");
  Page* n2_3=new Page("We acknowledge the odds stacked against us but are determined to\
 see our relationship through. As we part, I tell her I love her. With\
 a little hesitation, she replies in kind.  Year 3. One day in our separate\
 colleges, she tells me she wants an open relationship to see what\
 other people are like and encourages me to experience it as well.");
  Page* n2_3b=new Page("I tell her I don't like the idea and won't participate. A week\
 later, she admits to having sex with another man. I feel as if an\
 anvil has been placed on my chest. She asks me to forgive her.");
  Page* n2_3d=new Page("I tell her I'll try it out. A week later, she admits to having sex\
 with another man. I admit I've had sex with another woman. She tells me that she regrets her\
 decision and that she wants us to be exclusive again.");
  Page* n2_3f=new Page("I decide the act is unforgivable and halt all contact with her. She fades into memory.");
  Page* n2_4=new Page("I forgive her and ask if she will be with me again. We are both more hesitant\
 about our prospects but want to commit together again. Year 4. After a period of time, we grow apart\
 and our differences become more pronounced: in lifestyles, friends, and family. We don’t have very many\
 similar hobbies, go to different schools, and our parents dislike us.");
  Page* n2_4b=new Page("We realize we have too many differences to be happy together. We go our\
 separate ways with bittersweet memories that fade away as the years pass.");
  Page* n2_5=new Page("We struggle, slowly and painfully through our differences, swallowing our pride and preferences\
 to make compromises for each other. Time passes and we’ve made it through, together. Year 5. All the pain and heartache;\
 all the promises kept and unfulfilled; all the joy and laughter; it was all worth it. One night, as we walk through the\
 park where we first met, she stops me and gets down on her knees; I’m speechless. She pulls a small box from the pocket\
 of her jeans and reveals a ring to me. I can hear the question before she asks it.");
  Page* n2_5b=new Page("Her smile collapses, replaced by an anxious look. My heart skips a beat and I pull her up into a hug.\
 I kiss her cheek gently.");
  Page* n2_6=new Page("She blinks back tears ands nods, embracing me. We look towards the night sky,\
 with its stars shining brightly. The night sky darkens to the east, the blackness almost unnatural; \
 yet the sun has not long left the horizon. I look over her shoulder towards the tree line, from where a\
 blackness so complete emanates. I frown, puzzled at what it could be... Was there a power outage?\
 A light suddenly bursts white from the center, flashing, blinding… And then I am plunged into nothingness, black and empty.");
  Page* n2_7=new Page("No sound escapes my throat. A voice sounds in my head, inaudible at first; I try to\
 clear my mind, certain it is a hallucination, but the sounds and speech grow in volume, becoming deafening in the empty space.");

  n2_1->addOption("I should apologize.", n2_2);
  n2_1->addOption("She is just overreacting.", n2_1b);
  n2_1b->addOption("I should console her.",n2_2);
  n2_1b->addOption("I can leave her alone to think it out.", n2_1d);
  n2_1d->addOption("Return to beginning.", n1_1);
  n2_2->addOption("Tell her to have hope.", n2_3);
  n2_2->addOption("Admit it won't work out.", n2_2b);
  n2_2b->addOption("Return to beginning.", n1_1);
  n2_3->addOption("Agree.", n2_3d);
  n2_3->addOption("Don't agree.", n2_3b);
  n2_3b->addOption("Forgive her.",n2_4);
  n2_3b->addOption("Leave her.",n2_3f);
  n2_3d->addOption("Reciprocate her feelings.",n2_4);
  n2_3d->addOption("Leave her.",n2_3f);
  n2_3f->addOption("Return to beginning.", n1_1);
  n2_4->addOption("Try to reconcile our differences.",n2_5);
  n2_4->addOption("Admit we can't get over them.",n2_4b);
  n2_4b->addOption("Return to beginning.", n1_1);
  n2_5->addOption("Yes, I will.",n2_6);
  n2_5->addOption("I need time to think.",n2_5b);
  n2_5b->addOption("Give me some time.",n2_6);
  n2_6->addOption(" What the… ?!",n2_7);

  m_pages.push_back(n1_1);
  m_pages.push_back(n1_1b);
  m_pages.push_back(n1_2);
  m_pages.push_back(n1_2b);
  m_pages.push_back(n1_2c);
  m_pages.push_back(n1_3);
  m_pages.push_back(n2_1);
  m_pages.push_back(n2_1b);
  m_pages.push_back(n2_1d);
  m_pages.push_back(n2_2);
  m_pages.push_back(n2_2b);
  m_pages.push_back(n2_3);
  m_pages.push_back(n2_3b);
  m_pages.push_back(n2_3d);
  m_pages.push_back(n2_3f);
  m_pages.push_back(n2_4);
  m_pages.push_back(n2_5);
  m_pages.push_back(n2_5b);
  m_pages.push_back(n2_6);
  m_pages.push_back(n2_7);
  currentPage=m_pages[0];
}

void Arc::createArcTwo() {

}

void Arc::createArcThree() {

}


void Arc::choose(int choiceNum){
    currentPage=currentPage->getChosenPage(choiceNum);
    if(currentPage==nullptr) cout<<"Error: Tried to get a nullptr "<<endl;
    else currentPage->processEffects();
}

string Arc::toString(){
     string str="Pages List\n";
     for(unsigned i=0; i<m_pages.size(); i++)
         str+=m_pages[i]->toString()+'\n';
     return str;
}
