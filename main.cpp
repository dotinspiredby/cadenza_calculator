#include <iostream>
#include <array>
#include <algorithm>
#include <limits>
#include <iostream>

using namespace std;


class CadenzaSys {

public:
    CadenzaSys()= default;
    CadenzaSys(const size_t& input_root_tone);

    array <int, 6> scala;
    array <int, 6> hypo_scala;

    array <int, 2>              d;
    array <pair<int,int>, 2>    p;
    array <int, 2>              l;
    array <pair<int,int>, 2>    m;
    array <pair<int,int>, 2>    a;
    array <int, 2>              i;

private:

};


CadenzaSys::CadenzaSys(const size_t& root_tone) // ??
{
    scala[0] = (root_tone+2)%12;
    scala[1] = (root_tone+4)%12;
    scala[2] = (root_tone+5)%12;
    scala[3] = (root_tone+7)%12;
    scala[4] = (root_tone+9)%12;
    scala[5] = root_tone%12;

    transform(scala.begin(), scala.end(), hypo_scala.begin(), [](int i){return (i+7)%12;});


    //d[0] = abs((scala[0]-5)%12);
    d[0] = (scala[0]+7)%12;                                             // Dorian Secundaria
    d[1] = (scala[0]+3)%12;                                             // Dorian Tertiaria

    //p[0].first = abs((scala[1]-7)%12);
    p[0].first = (scala[1]+5)%12;                                       // Phrygian Secundaria
    p[0].second = numeric_limits<int>::infinity();                      // (the only variant)
    p[1].first = (scala[1]+3)%12;                                       // Phrygian Tertiaria I
    //p[1].second = abs((scala[1]-4)%12);
    p[1].second = (scala[1]+8)%12;                                      // Phrygian Tertiaria II

    //l[0] = abs((scala[2]-5)%12);
    l[0] = (scala[2]+7)%12;                                             // Lydian Secundaria
    l[1] = (scala[2]+4)%12;                                             // Lydian Tertiaria

    m[0].first = (scala[3]+5)%12;                                       // Myxolydian Secundaria I
    //m[0].second = abs((scala[3]-5)%12);
    m[0].second = (scala[3]+7)%12;                                      // Myxolydian Secundaria II
    m[1].first = m[0].second;                                           // Myxolydian Tertiaria I
    m[1].second = m[0].first;                                           // Myxolydian Tertiaria II

    a[0].first = (scala[4]+5)%12;                                       // Aeolian Secundaria I
    //a[0].second = abs((scala[4]-5)%12);
    a[0].second = (scala[4]+7)%12;                                      // Aeolian Secondaria II
    a[1].first = (scala[4]+3)%12;                                       // Aeolian Tertiaria
    a[1].second = numeric_limits<int>::infinity();                      // (the only variant)

    //i[0] = abs((scala[5]-5)%12);
    i[0] = (scala[5]+7)%12;                                             // Ionian Secundaria
    i[1] = (scala[5]+4)%12;                                             // Ionian Tertiaria

}



ostream& operator <<(ostream& out, CadenzaSys s) {

    out << "HYPO"           << '\t'                     << '\t' << "PRIMARIA"       << '\t' << "SECUNDARIA"                             << '\t' << "TERTIARIA"                          << '\n';
    out << s.hypo_scala[0]  << '\t' << "DORIAN"         << '\t' << s.scala[0]       << '\t' << s.d[0]                                   << '\t' << s.d[1]                               << '\n';
    out << s.hypo_scala[1]  << '\t' << "PHRYGIAN"       << '\t' << s.scala[1]       << '\t' << s.p[0].first                             << '\t' << s.p[1].first << '/' << s.p[1].second << '\n';
    out << s.hypo_scala[2]  << '\t' << "LYDIAN"         << '\t' << s.scala[2]       << '\t' << s.l[0]                                   << '\t' << s.l[1]                               << '\n';
    out << s.hypo_scala[3]  << '\t' << "MYXOLYDIAN"     << '\t' << s.scala[3]       << '\t' << s.m[0].first << '/' << s.m[0].second     << '\t' << s.m[1].first << '/' << s.m[1].second << '\n';
    out << s.hypo_scala[4]  << '\t' << "AEOLIAN"        << '\t' << s.scala[4]       << '\t' << s.a[0].first << '/' << s.a[0].second     << '\t' << s.a[1].first                         << '\n';
    out << s.hypo_scala[5]  << '\t' << "IONIAN"         << '\t' << s.scala[5]       << '\t' << s.i[0]                                   << '\t' << s.i[1]                               << '\n';

    return out;
}



int main()
{

    CadenzaSys system = CadenzaSys(3);
    cout << system;
    return 0;
}
