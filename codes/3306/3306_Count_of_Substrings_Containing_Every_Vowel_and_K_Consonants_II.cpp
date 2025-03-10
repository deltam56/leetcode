/**
 * 3306. Count of Substrings Containing Every Vowel and K Consonants II
 * You are given a string word and a non-negative integer k.

 * Return the total number of substrings of word that contain every vowel ('a', 'e', 'i', 'o', and 'u') at least once and exactly k consonants.
 * 
 * Example 1:
 * Input: word = "aeioqq", k = 1
 * Output: 0
 * Explanation:
 * There is no substring with every vowel.
 * 
 * Example 2:
 * Input: word = "aeiou", k = 0
 * Output: 1
 * Explanation:
 * The only substring with every vowel and zero consonants is word[0..4], which is "aeiou".
 * 
 * Example 3:
 * Input: word = "ieaouqqieaouqq", k = 1
 * Output: 3
 * Explanation:
 * The substrings with every vowel and one consonant are:
 * word[0..5], which is "ieaouq".
 * word[6..11], which is "qieaou".
 * word[7..12], which is "ieaouq".
 * 
 * Constraints:
 * 
 * 5 <= word.length <= 2 * 105
 * word consists only of lowercase English letters.
 * 0 <= k <= word.length - 5
 **/

#include <iostream>
#include <cassert>
#include <vector>
#include <print>
#include <string>
#include <unordered_map>

using namespace std; //편의성위해..
#if 0
class Solution {
public:
	long long countOfSubstrings(string word, int k) {
		long long count=0;
		for(int i= 0; i<word.length();i++){
			vector<int> vowcount(5,0);
			int concount = 0;
			for(int j = i ; j<word.length() && concount <= k;j++){
				switch(word[j]){
				case 'a': vowcount[4]+=1;    break;
				case 'e': vowcount[3]+=1;    break;
				case 'i': vowcount[2]+=1;    break;
				case 'o': vowcount[1]+=1;    break;
				case 'u': vowcount[0]+=1;    break;
				default:
					concount ++;
				}
				if(find(vowcount.begin(),vowcount.end(),0) == vowcount.end()&&
					   concount == k){
						count ++;
				}
			}
		}
		return count;
	}
};
#else
class Solution {
private:
    string vw = "aeiou"; // 모음 목록

    bool isVowel(char c) {
        return vw.find(c) != string::npos;
    }

public:
    long long countOfSubstrings(string word, int k) {
        int left = 0, mid = 0, vowels = 0, cnt[6] = {}, cnt1[6] = {};
        long long res = 0;

        for (int right = 0; right < word.size(); ++right) {
            int p = vw.find(word[right]) + 1; // 모음이면 1~5, 자음이면 0
            ++cnt[p];
            vowels += (cnt[p] == 1 && p); // 새로운 모음 등장 시 카운트 증가

            // 자음 개수가 k 초과하면 left 이동
            while (cnt[0] > k) {
                int lp = vw.find(word[left]) + 1;
                --cnt[lp];
                vowels -= (cnt[lp] == 0 && lp); // 특정 모음이 빠지면 vowels 감소
                left++;
            }

            // 모든 모음이 포함되고 자음 개수가 정확히 k일 때
            if (vowels == 5 && cnt[0] == k) {
                // mid 조정 (가능한 최소 left 찾기)
                if (mid < left) {
                    mid = left;
                    memset(cnt1, 0, sizeof(cnt1)); // 보조 윈도우 리셋
                }

                // mid를 증가시키면서 모음 중복을 줄여 더 작은 left 찾기
                for (int mp = vw.find(word[mid]) + 1; 
                     mp && cnt[mp] - cnt1[mp] > 1; 
                     mp = vw.find(word[++mid]) + 1) {
                    ++cnt1[mp];
                }

                res += mid - left + 1; // 가능한 substring 개수 추가
            }
        }

        return res;
    }
};
#endif
int main() {
	Solution sol;
	string word;
	int k;
	long long ans;
	long long res;
	word = "iqeaouqi";
	k = 2;
	ans = 3;
	res = sol.countOfSubstrings(word,k);
	println("word : {} \nans : {} , res : {}",word,ans , res);
	assert(ans == res);


	word = "aeioqq";
	k = 1;
	ans = 0;
	res = sol.countOfSubstrings(word,k);
	println("word : {} \nans : {} , res : {}",word,ans , res);
	assert(ans == res);

	word = "aeiou";
	k = 0;
	ans = 1;
	res = sol.countOfSubstrings(word,k);
	println("word : {}\n ans : {} , res : {}",word,ans , res);
	assert(ans == res);

	word = "ieaouqqieaouqq";
	k = 1;
	ans = 3;
	res = sol.countOfSubstrings(word,k);
	println("word : {}\n ans : {} , res : {}",word,ans , res);
	assert(ans == res);

	word = "aciiebbouideuaadbceodicooeubiaiobaeiuaocducouoaibdbdcbodbdoaiuiebbuuadcoocudiibocccioocaieuebiciuoeaabacbuddcubibbcbueieudbcdocuicibdeucuboiceeouuddebiidubuadeocoiobuddoidceeiicbebuducecucuaccocdddubuoaecdidubuouibiabdocdideuedbaoeaaeaiabebeooducbaiocbuodoabiuiobbueeeioibcudaiiioddiedeooeabuiucubuiabdaoacaaidceiboaababecouiiiudceaaoeodbddeaeedobdaedodiuabaedicbeucieidoaaouudeaaeabdcoaceubduiboauuoddauceuocbuiocdcdocudeacoaidbcoboeeocieubdduuboacddcecobecooeioaaubbodeauecdaicoidaacuciccauuodaacideiddbdbieuiiccbiedociueecuicudaaaadocaddbioiudcbueouidibeaicbuidodaeiiueubacdouuooeceoouueouauouodeiicobbaeoaueiooaoiecioiiduuebubcidicbbadccdbuieucobidobdcobceidoabcaaeuaoauecededduaedadducuebuibebbeuooodeaiaidcbiddubeieuebaoauoobobbuieiuciaidceaaiciiuueceobaadobdciadadaacouubbobaeeiabudbcauiacouicbbaaadbouuaeicadibbeeabebobdbcaaououadedeboecdoebocdddebubdebdcadeoacbciodbcooocieuicideiueauiuaiooiebdbiibouoadouudooadauobdobodccecaiuuucobibieeieaidibaabccdacdabbuaceidaeiduoiadeceocibuaoiaaeocicooodudeiacdaaeiiiiiobcbicicaaeobbiioaiibcoubuabcdbbiaicdibeoboceoiuuibecbouoecucdeiudicududiobbodiicdoceaboaaueuoaauodieidbeeabieuauicoddocceodbbdiuicediaoooiacbeeeiaabaocodiaubuoudbaecudebddbdddiuccucidauiiecbubcucbucdicacucocouuauuecuaeubeaodcuaebabicbacdaocaduudduiecbeuioeebudbeoodedabuococabeooduccbdbddiuiaeuacdbociaooobububaeaeooaeieaucudcacuueuocbucdbuiiueaabiedbdebcbdebdccoedddueeoibduoboiaaeobeccieacodobooubddbcoaoidbiiceiauicbcoaoeeobeouoabcaidddeodacbedidobacbiubdcaeibdbdbdobabceceucubeeioddubddddieidbiddcbcaeooacabcaaeeededdaioccbdoociobauaaoouiuacedudcebedbddcouocccuoaboubduebcoeedaeioidcabbdadcbocoidbudoadeaidbooiaeooacaaiudieccaodeouuaeiaoucidcbucouabboaacoeuidaoeeceeuuobceduoucbebbubudaboiuecuieoiobioiucududeuaedabduodeioioaodbiboucedbbeedeuibaibdbacduddaaocedbcouedoddeicaedabbieauuceuiaebueoobeoaaboodbiuodeucuebeduobdcuccdbcaiuduoicciaaecacuaeaiedeiaeaueciaiououoiauaodiuduboaobbuaodaaiiabaiiuuadaibidcecoboucdbuoiaauuuoeucdiaoecceeceeoeacobbebbicoebaaeoabcboeueuuudeaebiobuibbcoeaobueccuacadbboceaibobiuiuuddduoobdueiidobiiaedbceeidddoduduoebdiciaabeoudobiceiuiudoouioauibuaiuaaduaibueiaebcueeadceoaiebodoiocbebicabiudcceocbcdeooiicediiddeccobooocdooeccuiioaabbuuaiaiaceaaabboicoiiccdbiiuaiodeiaiaauoiidceeuuocaadbeoducbdeoboboabiueebouoaoiububocodoacudecoceeudaodoabdodcbiacobeucdcidodebodicidoceidbacuoeuodeiudcbbbcucubdeuccbbdcoaebibcdooebiucoubbduaeucicudabouaoboiaeoeciiauuebecieouoaucoeboucocuobdbdieidiaddicbbcobauuoiueedcedbaoobcobiiiiuddeabduicoiouieoaudioeeabibccaaicedaeccdoeboiabiabocabdaceducoauibeiuuocdabbiaeauoiiadbduoeddiecooueeaabcoeebdbuubcococcabadioiadccbbodeobdacebdddeuaudieecdcaadocoodiuaeduiuoaddceeoeicobocodiaeiuueueeaccbdaiddaudcocciibdbbieeiudedodooaeuuicecbeeaaioioiibabdoiiibdobubcbubioeboiiuciuuaaodcebiebauecdiadcaubcaioucddoaioubuidbdeceidoeiuiueoubuiiuabeboeueoaoddaoiauoacioeobaddidcceubdoudeieeauibcddaoocodiabiaaeidacdibbeoaieeoeuubaobaaucieuducidducciaboobcodaebiaiiboeeoioecabciuieuauidububaubcbboededcoeudueodeiuebaceoeieaddiacidceduududddoocooiiuabbcoaueoicbocociabiocoideioeiecuiiceceaceaeoebidcbibecucuoadbddeidcaideadceebcadceduecibuiicudddabadoaoiuuuuiudubccuudbeauciobecccdueauaoeadouccduudbieaiaiaoacuedaoaaeccodibuaddeoceeccaooaeceeceddiedccdieoidaueiiauoeouieiioueucoadbccodcbeaiaiuueiduebaaoicaacaoieuiueboodoocuibcbuauedcabuuiadcedecaeobcacadieacdeeoiduddciacduieaiouiabdaobuoaduaeoadebbdeiioabddaaooedcicabaddiucaabcboiiaobedoducacicbaocbbcadiideaeuececceboaoueaioaaaeeeeduabbabocaaeiidcaocueddbedeeeeduobbaeiadaebcioiuidciiceaaooeeuedcccbdicuoobddeaudaaceoudoooaobaiicboccibccdideuucdeueebeiudbuoebdccaiacbcuideeeeeboucoudubebaoieobaciaaiicouooebbbdbaubouodbcdbouebbdicacoicdeuaeodeaoeeciocbabiucuidabcoodbbiucicbuudccedbabiaececdouaobebocbidieduiabibcauiudbuadoidbiaicbbcebicbcaducbecuaaoeiacedeiadedceaudaaaideubuaiaeecauacaaduaoaaeaaadudaaeucdbeoouocbuiuabeocoudeodebbuoaeoceeodaouudobbdibebucdeuiidebiuauiiooaiucobbubuooicbauieuiidiibbiodueeaeodoaiobboedaaueaiiceaeaoaiueiaodouubcdocbboicieoboaciaiuaeueoauauioidicuiauuoedaducudbddciiubcuaccoouubuacabieudioobiobebacaeoaaodocucdeeecoiediiiauaodbeddoeiieocabieodbacbeubcdooeoecbobcooeeabodobebuoideobobecuuaucbubabuebooedcieeabdiciioaaaoeoiudeobcouebeiudbdccodebdbicuddoodouidbiucouoddocouiibcaeocaucioedubouciuabbacibucidbodoiaueuiddocddoocceeceouboccebcceaiuaauuoiiibebduceiaibbiaobcaiaucauioiieubbuedbdbudeideucccbbaieeuuucciboccbcbauiububbduedduacadbaicbodaadeiaiudadcaucbibebuuaecoocbcoouiaeebebeabeocucdaaoiuauucideedeoiueeabacuebcbieeaduuiiecdidbiuiouucuuoaeoibuodcdubbceidiaiauocadoabccuceeiouueeaeddcoudiouiebooabeodiddidcuaabdceeacbouieoooubbccoocececiebbaaaccaeiiuubbieodeeddooaobabbadoocuecudcoaoecedeeboceuoduadiebediiieuaduoideiadobbcaibaobcdcuoidouboiicaeebbaaaebeddaaaudadiidcecdeabdoeacueiauuabdbeueeoaicdacbueboebaocoauoicicdoedebeubuabueicbiaoeeiacbdcicecdicouiodiubboieeaaoabddoaibidoduuobiooddoaciuucicedbacddicuddciecaieioeocdcieebaidbcediccdicbiouiuaaddoiaaaeaucbeueidaaebucciaeaaciidiuioaioiedbaaucuciibicoieouoouebaeeoucbeeidibucauidoiiaecubdcedudacoebaeoeiaieaccceooeoauuieooaeiiieboaaabcbaedbduiodccuedubciaabbbaebucdcacauaaeeeubadabudeuiadceooubdboacoieuabeaadecbedccobcuddbccbccbidcbbdodebaediauuieicediedicucauiuebiciudboeoedccccbcceaeduoioeaicoibaadooddciciedauudeabiadcdoeuaabceobcdduduubioobaeuoiocbiuubbdiiidbuoiuueocedubiaedbiecubccaeuuoaeuodidcodcobibbbidebbbuuubeoebueaaoiuadcbcbuoacbauobaeeuduuudbcceceeeuduidoauudieabaiudicdaaoaeeecuubuoaeucebaebuicdoubiceaceoabbdoubdeaeoaciuedoioucodbcuuacddaedoeioeeeuoadcieoaudccddubdaauuadibddecouueaceueoouooeueicdiubecbcocecbbbauiaiubbioebccdicbeecaiedodcdecbobbadieddcbecidbaiceuodiaidiucuiabbooiuacaoeduoocuauoiiocooodddibbuedacbaaoddoaduocoiibobiieieeaudeuadoodiocbeeooceouduoiooicduobediebcbubuuuudcediboeicuoicouibbocdibaaadbceiuaduididdiddocuciieoebddddbaedeeaoeuicedoidobicooeebcibbocociooabduuecocaaeuiibuaadcbiadcoeicuoedcdudbiaoduoeioicuadiooeuoeeecoubcoccdeeeoouaeouideodiecdeddeaadiedebuueceddidbdduibccoiadbdbuiidddudidcebaeouaauiabuaauoeicbdeuociceoadoeueducuuiicddbeudidbauobduaeuicodedeaoeebcbiucdbebccecbueeoeaoouabbbbabccauoeecdddieuuiccoceccacbaaueoeeiubeacecbiauaecaaoecdcbucidiccuceaieaibiccaciuobeauebcdobucaoidcbcbiceucbadceibacicaabidicuiiooebbdiieuidcoidoiuauidbideiooibeebaoueodbabouuuiiedboicdiiaieaidiuiuoeoebuouooauudooeobdbiaiciuieiodeuuccecboiioaocuuideeucuiieioedeaadceddideaooiaooeuedabacbcdbdoaiiadcueecbeeooabadubbooioeacuudduocdacacbcouiuoiudeicaodobueiidoaeeoiuuuidduoauiicoidbdibbeuudbeeecudbocdiaoduiioeuedocbecoaoiaeceuuaiaeeeecdaebibieodiboideaiiuaciaoiacuacbbibocaiboaieodecuibcbicaadiaaiouaudadcobeadibdciooieeeeoadedodeaauebdebcecoaibcoouecciaibuuciieuueaeoauecodcdboecbacbcuicobccbeodicuadodbadbuicaadcacboicaedebaiaadbbadeeccbcuiccodiabocdobdaoaauocaaieuoabooodeeobcuaiiudoaucuedodaeiabeooiiaoeaduiioucdaioaieiabioiioceaoiaaabbouibcbduuuaibuuicbdiddbdbdabdcedcieicubdudeboocauebiouoicdcbbeidiuibuecccdcdbabudbdiuidcbubbdiiiuoodbciaduoueoeibddbudiieidbobiueiicubbddoboeaacubuoedcebidieobbeeouuocobiibebeoodeodddaouucbdebbucdbuoudaidebbeebcuadbocoodebdcecodidbbeodaaiaudoiauoiuoobaecdcucoubaudioaiuaocaccboaadbedcieibdbeaiaaocbdabieiddcbaooeoduiicibediaeaubcdaauuaebcibbuoddubeebbudicocicaacebcacbieoioieubcudbiuuccddubiuuaeicdbuibaadueociebeoiaidaaieoibdudeciadciecbcdcucebicdeaaabeaooauduaiobduaeidcuaicudueoeadbubddbacdeaeebdbuaiiuuieeocdaeuobodbccduaueoaauiuoeauiodibcdoadoueaiouciuadoidobbuccuccabaddboduacedueiiedbaadoiaacaucdeaeduoebocdubicoeeboudobuiduauddecebceiocbeaeboduouaddiiadbbudecuueebiaiauaeodbeaaaibdcacccdcadudeooibuidueedbboebueucaacbiiiacbieoaaebebauddcobcuuuieiaeeccbeiauaioibbbbeaeuoacdaebabbcaicouabeuabbdboaobocaoocuiuieueabccuuocauccaocbdiicbocbidcdibudacaoduuibciaaeobcuoeiaceudiceiiodabaddciddobioiouabeueeebudeueuedoaeoiaaeoaobaduiecbuauueddaaeaducdeobiuieeocdoiaaccaueuadcooedaabiuaobeeeudibaaaoibbcbcecuoabibdadcieoicouddidudbuacaacacacbadioabecdcceocbciboocboaiioieueeceeiiedueoddoaeuucbebaucbedciuocabuuucioabaeueaoiiucbbcbdcbaobuucbiuoidicouiaoeiibauadoaeccueuaaaucuccadceaiociuauodooicdbbadaubeaiobaeoiuueobcucdubuoebebccboeeeuobaiaadeddiduuaecbeeiauodudiiecddduoobbebbacedeododaiiadaudcbaoeeocuaoddcibibdoiciaacuebiaccececdaieueiiabbeioduuioiiococuadideuudcauaediaaeceocobaboeaciedbebuccaeieiobcdcauuiocabaacueciieieiouoabauoaiboeuoueeboauiacoccbodeioduciieueoediuiaicoueuiuieocodcuaoiuiadidubidbcdebadobbuaccaaiaiaciiooeebeeieaeebbueboodoaeeuucoeaeduuaiouduouaeducaeaaciiibeecodccdouadiouiocbbeooueeeouaccieuaieeiccuacdcbdboubeeaidbaducdceodcabeoibibouucodceubdcaouocoioacbaeeuubcaeoeioeibcibubuaaauoeddauubudeacioeoedobebaaobboecbadaaoiodedaoueboeuaecebdcceeoddaauuocdabeioubaoebeiaubiaiodieuceioebucabdaaboeoibucucodecieuodaueciooabcibcaaiidccaiuuuouboeccueddeeobedeieaoeadcudebbedbbdudadcceoeubiceduciabebiaiduiuobuiacbciboeicoaodeaauuubdcoeeieaeooicoueiecdeoaaaibbuduaoiocdoceececaccoeoodeoeaccoaibaoiibiadbcuoiebbuboibddiuciubbiaccedbbabbaoudeudeoaeuaaaoebcucaaeibcidbudueciddbciuuoaeubeiecieaoeboueodudcdouubadcadouiuabioedeabicaubouoaadocieadcecioeoaidaadbbbbcediouuoocudebaeociebocoududadbccubaudecoaiaaiaedieuoeicceciecdbceibicebdicococccuaieudocuccbcoocbaebaeebdciceubebedaoudoaobdeecieaauoueuiedeboebdouucadadaaaauoaaouiocaciudduaaiaaaeoaobeiuudbuaeoaabadcadaabcodcadeabibaoiueieecdoabcidboduoibeibebauccbueocebbbdibuobdcieedoeocidciddodeoobuaedbudccdcobabdeeicdeudoubadiiouaudaaeiiaiecaeebececbbbubiuiiicaiidbucbuducccdeuiecaiaubebidoecicoebccceuauoibeidcabbueaudeddcbdabceuiiaucoadcocedcuubbaaacedadcodaicebecudobodieiiceeudbecoicdbiauecabdoduecoaaadacduadodeeoodbibcaaccuobidbeucoeaoaeccducicidbidudiceaoucuauaboobeeudbubaiueiuacdcoacduidobddeacucaceeaibocabddaaaiubdcubaacobocuubeuicbcouubiieoicdbddeoeedccibuddeacuicucuaeicueeccuabaieaauaeccidcbaeoduibiebbcedoeiddacabeouiiebueuiuceeaocdoaeeiidooucdocoodeaeodoeuiiuaebacuuadobcoaeudeidiuuooecbdeuuoooacbdaiiedaiiedueuieeaoobebbeboueoicbcaadboiddbbodaacaibcieeuuddebibbodaaebeaibuubobueuiccadooibdbioiebceedaaaaoadebauucbebocbbbbeeaibceecbaadooedccieicbueecdbciicdibuaaebubeaebaciaibaaubceacocubbuuoudbddeadobboideucibcioubacciducobuaooaeibu";
	k = 9059;
	ans = 0;
	res = sol.countOfSubstrings(word,k);
	println("word : very long\n ans : {} , res : {}",ans , res);
	assert(ans == res);


	cout << "Accepted!" <<endl;
	return 0;
}
