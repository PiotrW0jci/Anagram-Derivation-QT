#include "handletextfield.h"
#include "anagrams.h"


using namespace  std;

/*
 * This class handles interactions with the text field
 */




HandleTextField::HandleTextField(QObject *parent) :
    QObject(parent)
{
}

void HandleTextField::handleSubmitTextField(const QString &in)
{

    /*
     * This class handles interactions with the text field
     */
    qDebug() << "c++: HandleTextField::handleSubmitTextField:"  <<in;
    if(in.size()==3){
        threeLetterWord=in.toStdString();
    }
    else{
        pathFile=in.toStdString();
        anagrams Anagram;
        emit setTextField(QVariant(Anagram.derivation(threeLetterWord,pathFile)));


    }

    //
}
