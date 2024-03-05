/*
  Simple DirectMedia Layer
  Copyright (C) 1997-2024 Sam Lantinga <slouken@libsdl.org>

  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.

  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely, subject to the following restrictions:

  1. The origin of this software must not be misrepresented; you must not
     claim that you wrote the original software. If you use this software
     in a product, an acknowledgment in the product documentation would be
     appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.
  3. This notice may not be removed or altered from any source distribution.
*/

// DO NOT EDIT, THIS FILE WAS GENERATED BY build-scripts/gen_audio_resampler_filter.c

#define RESAMPLER_ZERO_CROSSINGS 5
#define RESAMPLER_BITS_PER_SAMPLE 16
#define RESAMPLER_BITS_PER_ZERO_CROSSING ((RESAMPLER_BITS_PER_SAMPLE / 2) + 1)
#define RESAMPLER_SAMPLES_PER_ZERO_CROSSING (1 << RESAMPLER_BITS_PER_ZERO_CROSSING)
#define RESAMPLER_FILTER_SIZE (RESAMPLER_SAMPLES_PER_ZERO_CROSSING * RESAMPLER_ZERO_CROSSINGS)

static const float ResamplerFilter[RESAMPLER_FILTER_SIZE] = {
     1.000000000f, 0.000000000f,-0.000000000f, 0.000000000f,-0.000000000f,
     0.999993165f,-0.001679888f, 0.000529080f,-0.000151513f, 0.000027455f,
     0.999972661f,-0.003351212f, 0.001055794f,-0.000302183f, 0.000054683f,
     0.999938488f,-0.005013955f, 0.001580128f,-0.000452009f, 0.000081685f,
     0.999890647f,-0.006668099f, 0.002102071f,-0.000600987f, 0.000108459f,
     0.999829139f,-0.008313629f, 0.002621611f,-0.000749115f, 0.000135007f,
     0.999753966f,-0.009950528f, 0.003138734f,-0.000896389f, 0.000161328f,
     0.999665131f,-0.011578779f, 0.003653429f,-0.001042807f, 0.000187423f,
     0.999562634f,-0.013198368f, 0.004165684f,-0.001188367f, 0.000213291f,
     0.999446480f,-0.014809279f, 0.004675488f,-0.001333066f, 0.000238933f,
     0.999316672f,-0.016411497f, 0.005182828f,-0.001476901f, 0.000264348f,
     0.999173212f,-0.018005007f, 0.005687694f,-0.001619871f, 0.000289537f,
     0.999016105f,-0.019589795f, 0.006190074f,-0.001761971f, 0.000314501f,
     0.998845356f,-0.021165846f, 0.006689957f,-0.001903201f, 0.000339239f,
     0.998660968f,-0.022733147f, 0.007187332f,-0.002043558f, 0.000363751f,
     0.998462946f,-0.024291684f, 0.007682189f,-0.002183039f, 0.000388037f,
     0.998251297f,-0.025841443f, 0.008174516f,-0.002321643f, 0.000412099f,
     0.998026026f,-0.027382413f, 0.008664303f,-0.002459367f, 0.000435935f,
     0.997787138f,-0.028914579f, 0.009151540f,-0.002596209f, 0.000459547f,
     0.997534641f,-0.030437930f, 0.009636217f,-0.002732167f, 0.000482934f,
     0.997268542f,-0.031952453f, 0.010118324f,-0.002867240f, 0.000506097f,
     0.996988847f,-0.033458137f, 0.010597850f,-0.003001425f, 0.000529036f,
     0.996695563f,-0.034954970f, 0.011074786f,-0.003134721f, 0.000551752f,
     0.996388700f,-0.036442941f, 0.011549123f,-0.003267125f, 0.000574244f,
     0.996068266f,-0.037922039f, 0.012020851f,-0.003398637f, 0.000596512f,
     0.995734268f,-0.039392253f, 0.012489961f,-0.003529253f, 0.000618558f,
     0.995386717f,-0.040853574f, 0.012956443f,-0.003658973f, 0.000640382f,
     0.995025621f,-0.042305990f, 0.013420290f,-0.003787796f, 0.000661984f,
     0.994650990f,-0.043749493f, 0.013881491f,-0.003915718f, 0.000683363f,
     0.994262835f,-0.045184072f, 0.014340039f,-0.004042740f, 0.000704522f,
     0.993861166f,-0.046609719f, 0.014795924f,-0.004168860f, 0.000725459f,
     0.993445994f,-0.048026424f, 0.015249139f,-0.004294075f, 0.000746176f,
     0.993017331f,-0.049434180f, 0.015699676f,-0.004418386f, 0.000766672f,
     0.992575187f,-0.050832978f, 0.016147525f,-0.004541790f, 0.000786949f,
     0.992119574f,-0.052222809f, 0.016592680f,-0.004664287f, 0.000807006f,
     0.991650506f,-0.053603666f, 0.017035133f,-0.004785875f, 0.000826844f,
     0.991167995f,-0.054975543f, 0.017474875f,-0.004906553f, 0.000846464f,
     0.990672054f,-0.056338431f, 0.017911900f,-0.005026320f, 0.000865865f,
     0.990162696f,-0.057692323f, 0.018346201f,-0.005145175f, 0.000885049f,
     0.989639935f,-0.059037214f, 0.018777770f,-0.005263117f, 0.000904016f,
     0.989103786f,-0.060373097f, 0.019206599f,-0.005380146f, 0.000922766f,
     0.988554262f,-0.061699966f, 0.019632684f,-0.005496260f, 0.000941300f,
     0.987991380f,-0.063017815f, 0.020056015f,-0.005611458f, 0.000959619f,
     0.987415153f,-0.064326639f, 0.020476588f,-0.005725741f, 0.000977722f,
     0.986825598f,-0.065626433f, 0.020894396f,-0.005839106f, 0.000995611f,
     0.986222730f,-0.066917192f, 0.021309432f,-0.005951554f, 0.001013285f,
     0.985606567f,-0.068198912f, 0.021721690f,-0.006063084f, 0.001030746f,
     0.984977124f,-0.069471588f, 0.022131165f,-0.006173695f, 0.001047994f,
     0.984334418f,-0.070735217f, 0.022537850f,-0.006283387f, 0.001065030f,
     0.983678468f,-0.071989794f, 0.022941741f,-0.006392159f, 0.001081853f,
     0.983009290f,-0.073235317f, 0.023342830f,-0.006500011f, 0.001098466f,
     0.982326903f,-0.074471782f, 0.023741114f,-0.006606943f, 0.001114868f,
     0.981631326f,-0.075699186f, 0.024136587f,-0.006712954f, 0.001131059f,
     0.980922577f,-0.076917527f, 0.024529243f,-0.006818044f, 0.001147042f,
     0.980200675f,-0.078126804f, 0.024919078f,-0.006922213f, 0.001162815f,
     0.979465640f,-0.079327013f, 0.025306087f,-0.007025460f, 0.001178380f,
     0.978717491f,-0.080518153f, 0.025690266f,-0.007127786f, 0.001193738f,
     0.977956250f,-0.081700223f, 0.026071609f,-0.007229191f, 0.001208889f,
     0.977181936f,-0.082873221f, 0.026450113f,-0.007329674f, 0.001223833f,
     0.976394570f,-0.084037148f, 0.026825773f,-0.007429235f, 0.001238572f,
     0.975594175f,-0.085192002f, 0.027198586f,-0.007527875f, 0.001253106f,
     0.974780770f,-0.086337783f, 0.027568547f,-0.007625593f, 0.001267436f,
     0.973954379f,-0.087474491f, 0.027935652f,-0.007722391f, 0.001281562f,
     0.973115024f,-0.088602126f, 0.028299898f,-0.007818267f, 0.001295485f,
     0.972262727f,-0.089720690f, 0.028661282f,-0.007913223f, 0.001309207f,
     0.971397512f,-0.090830182f, 0.029019799f,-0.008007258f, 0.001322726f,
     0.970519401f,-0.091930604f, 0.029375448f,-0.008100373f, 0.001336045f,
     0.969628418f,-0.093021958f, 0.029728224f,-0.008192568f, 0.001349164f,
     0.968724588f,-0.094104245f, 0.030078125f,-0.008283845f, 0.001362084f,
     0.967807935f,-0.095177467f, 0.030425148f,-0.008374202f, 0.001374806f,
     0.966878483f,-0.096241627f, 0.030769290f,-0.008463642f, 0.001387329f,
     0.965936258f,-0.097296726f, 0.031110550f,-0.008552163f, 0.001399656f,
     0.964981285f,-0.098342768f, 0.031448923f,-0.008639768f, 0.001411786f,
     0.964013590f,-0.099379756f, 0.031784409f,-0.008726456f, 0.001423721f,
     0.963033199f,-0.100407693f, 0.032117005f,-0.008812229f, 0.001435461f,
     0.962040138f,-0.101426582f, 0.032446709f,-0.008897086f, 0.001447008f,
     0.961034434f,-0.102436428f, 0.032773519f,-0.008981030f, 0.001458361f,
     0.960016114f,-0.103437235f, 0.033097434f,-0.009064060f, 0.001469522f,
     0.958985206f,-0.104429007f, 0.033418451f,-0.009146178f, 0.001480492f,
     0.957941737f,-0.105411749f, 0.033736571f,-0.009227385f, 0.001491271f,
     0.956885736f,-0.106385466f, 0.034051790f,-0.009307680f, 0.001501860f,
     0.955817231f,-0.107350163f, 0.034364109f,-0.009387067f, 0.001512261f,
     0.954736250f,-0.108305845f, 0.034673526f,-0.009465545f, 0.001522473f,
     0.953642823f,-0.109252518f, 0.034980040f,-0.009543115f, 0.001532497f,
     0.952536979f,-0.110190189f, 0.035283651f,-0.009619779f, 0.001542336f,
     0.951418748f,-0.111118864f, 0.035584357f,-0.009695538f, 0.001551988f,
     0.950288160f,-0.112038548f, 0.035882158f,-0.009770393f, 0.001561456f,
     0.949145245f,-0.112949250f, 0.036177055f,-0.009844346f, 0.001570741f,
     0.947990034f,-0.113850976f, 0.036469046f,-0.009917397f, 0.001579842f,
     0.946822559f,-0.114743733f, 0.036758132f,-0.009989548f, 0.001588761f,
     0.945642850f,-0.115627529f, 0.037044312f,-0.010060800f, 0.001597498f,
     0.944450939f,-0.116502372f, 0.037327588f,-0.010131156f, 0.001606056f,
     0.943246858f,-0.117368270f, 0.037607958f,-0.010200615f, 0.001614434f,
     0.942030639f,-0.118225231f, 0.037885424f,-0.010269180f, 0.001622633f,
     0.940802316f,-0.119073264f, 0.038159985f,-0.010336852f, 0.001630655f,
     0.939561921f,-0.119912378f, 0.038431644f,-0.010403633f, 0.001638500f,
     0.938309487f,-0.120742582f, 0.038700400f,-0.010469524f, 0.001646169f,
     0.937045048f,-0.121563886f, 0.038966254f,-0.010534527f, 0.001653663f,
     0.935768638f,-0.122376299f, 0.039229208f,-0.010598644f, 0.001660984f,
     0.934480291f,-0.123179830f, 0.039489262f,-0.010661876f, 0.001668131f,
     0.933180042f,-0.123974491f, 0.039746418f,-0.010724225f, 0.001675106f,
     0.931867925f,-0.124760291f, 0.040000678f,-0.010785693f, 0.001681910f,
     0.930543975f,-0.125537242f, 0.040252042f,-0.010846282f, 0.001688544f,
     0.929208228f,-0.126305353f, 0.040500513f,-0.010905994f, 0.001695008f,
     0.927860720f,-0.127064637f, 0.040746092f,-0.010964829f, 0.001701305f,
     0.926501487f,-0.127815104f, 0.040988782f,-0.011022792f, 0.001707433f,
     0.925130565f,-0.128556767f, 0.041228583f,-0.011079882f, 0.001713396f,
     0.923747991f,-0.129289637f, 0.041465499f,-0.011136103f, 0.001719193f,
     0.922353802f,-0.130013726f, 0.041699532f,-0.011191456f, 0.001724825f,
     0.920948034f,-0.130729047f, 0.041930683f,-0.011245944f, 0.001730294f,
     0.919530726f,-0.131435613f, 0.042158956f,-0.011299568f, 0.001735601f,
     0.918101916f,-0.132133435f, 0.042384354f,-0.011352330f, 0.001740746f,
     0.916661641f,-0.132822528f, 0.042606878f,-0.011404234f, 0.001745730f,
     0.915209940f,-0.133502905f, 0.042826532f,-0.011455280f, 0.001750555f,
     0.913746852f,-0.134174578f, 0.043043318f,-0.011505472f, 0.001755221f,
     0.912272416f,-0.134837563f, 0.043257241f,-0.011554812f, 0.001759730f,
     0.910786671f,-0.135491873f, 0.043468303f,-0.011603301f, 0.001764082f,
     0.909289657f,-0.136137522f, 0.043676506f,-0.011650942f, 0.001768278f,
     0.907781413f,-0.136774525f, 0.043881856f,-0.011697738f, 0.001772320f,
     0.906261980f,-0.137402897f, 0.044084355f,-0.011743690f, 0.001776208f,
     0.904731398f,-0.138022653f, 0.044284007f,-0.011788802f, 0.001779944f,
     0.903189708f,-0.138633807f, 0.044480816f,-0.011833076f, 0.001783528f,
     0.901636952f,-0.139236376f, 0.044674785f,-0.011876514f, 0.001786962f,
     0.900073170f,-0.139830375f, 0.044865920f,-0.011919118f, 0.001790246f,
     0.898498403f,-0.140415819f, 0.045054222f,-0.011960892f, 0.001793381f,
     0.896912695f,-0.140992726f, 0.045239698f,-0.012001838f, 0.001796369f,
     0.895316086f,-0.141561111f, 0.045422352f,-0.012041958f, 0.001799211f,
     0.893708620f,-0.142120991f, 0.045602186f,-0.012081256f, 0.001801907f,
     0.892090339f,-0.142672383f, 0.045779208f,-0.012119733f, 0.001804459f,
     0.890461286f,-0.143215304f, 0.045953420f,-0.012157393f, 0.001806868f,
     0.888821505f,-0.143749771f, 0.046124828f,-0.012194238f, 0.001809134f,
     0.887171038f,-0.144275802f, 0.046293436f,-0.012230270f, 0.001811259f,
     0.885509930f,-0.144793414f, 0.046459250f,-0.012265494f, 0.001813243f,
     0.883838224f,-0.145302625f, 0.046622274f,-0.012299911f, 0.001815089f,
     0.882155965f,-0.145803453f, 0.046782515f,-0.012333524f, 0.001816796f,
     0.880463198f,-0.146295917f, 0.046939976f,-0.012366337f, 0.001818366f,
     0.878759967f,-0.146780035f, 0.047094664f,-0.012398351f, 0.001819800f,
     0.877046317f,-0.147255826f, 0.047246583f,-0.012429571f, 0.001821099f,
     0.875322295f,-0.147723309f, 0.047395741f,-0.012459998f, 0.001822264f,
     0.873587944f,-0.148182503f, 0.047542141f,-0.012489637f, 0.001823295f,
     0.871843312f,-0.148633428f, 0.047685790f,-0.012518489f, 0.001824196f,
     0.870088444f,-0.149076103f, 0.047826695f,-0.012546558f, 0.001824965f,
     0.868323386f,-0.149510548f, 0.047964860f,-0.012573847f, 0.001825604f,
     0.866548186f,-0.149936783f, 0.048100292f,-0.012600359f, 0.001826115f,
     0.864762890f,-0.150354828f, 0.048232997f,-0.012626097f, 0.001826498f,
     0.862967545f,-0.150764704f, 0.048362981f,-0.012651064f, 0.001826754f,
     0.861162199f,-0.151166432f, 0.048490252f,-0.012675264f, 0.001826885f,
     0.859346899f,-0.151560031f, 0.048614814f,-0.012698699f, 0.001826891f,
     0.857521693f,-0.151945524f, 0.048736676f,-0.012721373f, 0.001826774f,
     0.855686629f,-0.152322931f, 0.048855842f,-0.012743288f, 0.001826534f,
     0.853841755f,-0.152692274f, 0.048972321f,-0.012764449f, 0.001826173f,
     0.851987121f,-0.153053574f, 0.049086119f,-0.012784858f, 0.001825691f,
     0.850122774f,-0.153406854f, 0.049197244f,-0.012804518f, 0.001825091f,
     0.848248764f,-0.153752135f, 0.049305701f,-0.012823434f, 0.001824372f,
     0.846365140f,-0.154089440f, 0.049411498f,-0.012841607f, 0.001823536f,
     0.844471951f,-0.154418791f, 0.049514643f,-0.012859042f, 0.001822584f,
     0.842569248f,-0.154740210f, 0.049615142f,-0.012875742f, 0.001821517f,
     0.840657079f,-0.155053721f, 0.049713003f,-0.012891710f, 0.001820336f,
     0.838735496f,-0.155359346f, 0.049808234f,-0.012906950f, 0.001819042f,
     0.836804549f,-0.155657108f, 0.049900842f,-0.012921465f, 0.001817636f,
     0.834864288f,-0.155947032f, 0.049990834f,-0.012935259f, 0.001816120f,
     0.832914765f,-0.156229140f, 0.050078219f,-0.012948334f, 0.001814493f,
     0.830956029f,-0.156503456f, 0.050163005f,-0.012960695f, 0.001812758f,
     0.828988133f,-0.156770004f, 0.050245198f,-0.012972345f, 0.001810916f,
     0.827011128f,-0.157028808f, 0.050324808f,-0.012983287f, 0.001808967f,
     0.825025066f,-0.157279893f, 0.050401842f,-0.012993525f, 0.001806912f,
     0.823029998f,-0.157523282f, 0.050476308f,-0.013003063f, 0.001804753f,
     0.821025977f,-0.157759001f, 0.050548215f,-0.013011904f, 0.001802491f,
     0.819013055f,-0.157987074f, 0.050617571f,-0.013020051f, 0.001800126f,
     0.816991284f,-0.158207526f, 0.050684384f,-0.013027509f, 0.001797660f,
     0.814960718f,-0.158420382f, 0.050748664f,-0.013034280f, 0.001795094f,
     0.812921409f,-0.158625668f, 0.050810417f,-0.013040370f, 0.001792428f,
     0.810873410f,-0.158823410f, 0.050869654f,-0.013045780f, 0.001789664f,
     0.808816775f,-0.159013631f, 0.050926382f,-0.013050515f, 0.001786804f,
     0.806751557f,-0.159196360f, 0.050980610f,-0.013054579f, 0.001783847f,
     0.804677811f,-0.159371620f, 0.051032348f,-0.013057974f, 0.001780795f,
     0.802595589f,-0.159539440f, 0.051081605f,-0.013060706f, 0.001777649f,
     0.800504946f,-0.159699844f, 0.051128389f,-0.013062778f, 0.001774411f,
     0.798405936f,-0.159852860f, 0.051172709f,-0.013064192f, 0.001771080f,
     0.796298614f,-0.159998514f, 0.051214574f,-0.013064954f, 0.001767659f,
     0.794183034f,-0.160136832f, 0.051253995f,-0.013065067f, 0.001764147f,
     0.792059252f,-0.160267843f, 0.051290979f,-0.013064535f, 0.001760547f,
     0.789927322f,-0.160391572f, 0.051325537f,-0.013063361f, 0.001756860f,
     0.787787300f,-0.160508047f, 0.051357678f,-0.013061549f, 0.001753085f,
     0.785639241f,-0.160617296f, 0.051387412f,-0.013059104f, 0.001749225f,
     0.783483200f,-0.160719346f, 0.051414747f,-0.013056029f, 0.001745280f,
     0.781319234f,-0.160814225f, 0.051439694f,-0.013052327f, 0.001741252f,
     0.779147398f,-0.160901960f, 0.051462263f,-0.013048003f, 0.001737141f,
     0.776967749f,-0.160982580f, 0.051482462f,-0.013043061f, 0.001732948f,
     0.774780342f,-0.161056113f, 0.051500303f,-0.013037504f, 0.001728675f,
     0.772585234f,-0.161122587f, 0.051515795f,-0.013031336f, 0.001724323f,
     0.770382481f,-0.161182031f, 0.051528947f,-0.013024562f, 0.001719892f,
     0.768172142f,-0.161234473f, 0.051539771f,-0.013017185f, 0.001715383f,
     0.765954271f,-0.161279942f, 0.051548275f,-0.013009209f, 0.001710798f,
     0.763728927f,-0.161318466f, 0.051554471f,-0.013000638f, 0.001706137f,
     0.761496167f,-0.161350075f, 0.051558368f,-0.012991476f, 0.001701402f,
     0.759256048f,-0.161374798f, 0.051559977f,-0.012981727f, 0.001696593f,
     0.757008627f,-0.161392665f, 0.051559309f,-0.012971395f, 0.001691712f,
     0.754753963f,-0.161403704f, 0.051556372f,-0.012960484f, 0.001686760f,
     0.752492113f,-0.161407945f, 0.051551179f,-0.012948997f, 0.001681737f,
     0.750223135f,-0.161405418f, 0.051543739f,-0.012936940f, 0.001676644f,
     0.747947088f,-0.161396153f, 0.051534064f,-0.012924315f, 0.001671483f,
     0.745664029f,-0.161380179f, 0.051522163f,-0.012911128f, 0.001666254f,
     0.743374018f,-0.161357527f, 0.051508048f,-0.012897381f, 0.001660959f,
     0.741077112f,-0.161328227f, 0.051491729f,-0.012883079f, 0.001655598f,
     0.738773370f,-0.161292309f, 0.051473217f,-0.012868227f, 0.001650173f,
     0.736462852f,-0.161249804f, 0.051452522f,-0.012852827f, 0.001644684f,
     0.734145616f,-0.161200742f, 0.051429657f,-0.012836884f, 0.001639133f,
     0.731821721f,-0.161145154f, 0.051404631f,-0.012820403f, 0.001633520f,
     0.729491227f,-0.161083070f, 0.051377457f,-0.012803386f, 0.001627846f,
     0.727154193f,-0.161014523f, 0.051348144f,-0.012785839f, 0.001622112f,
     0.724810678f,-0.160939542f, 0.051316704f,-0.012767765f, 0.001616320f,
     0.722460743f,-0.160858158f, 0.051283148f,-0.012749169f, 0.001610470f,
     0.720104446f,-0.160770404f, 0.051247488f,-0.012730054f, 0.001604563f,
     0.717741848f,-0.160676310f, 0.051209734f,-0.012710425f, 0.001598600f,
     0.715373009f,-0.160575909f, 0.051169898f,-0.012690285f, 0.001592582f,
     0.712997988f,-0.160469230f, 0.051127991f,-0.012669640f, 0.001586510f,
     0.710616847f,-0.160356307f, 0.051084025f,-0.012648492f, 0.001580385f,
     0.708229645f,-0.160237171f, 0.051038012f,-0.012626846f, 0.001574207f,
     0.705836443f,-0.160111854f, 0.050989962f,-0.012604706f, 0.001567979f,
     0.703437301f,-0.159980389f, 0.050939887f,-0.012582077f, 0.001561700f,
     0.701032280f,-0.159842806f, 0.050887799f,-0.012558961f, 0.001555372f,
     0.698621441f,-0.159699138f, 0.050833709f,-0.012535365f, 0.001548995f,
     0.696204845f,-0.159549419f, 0.050777630f,-0.012511290f, 0.001542571f,
     0.693782552f,-0.159393679f, 0.050719572f,-0.012486743f, 0.001536101f,
     0.691354624f,-0.159231952f, 0.050659547f,-0.012461726f, 0.001529584f,
     0.688921121f,-0.159064270f, 0.050597568f,-0.012436245f, 0.001523023f,
     0.686482106f,-0.158890666f, 0.050533646f,-0.012410302f, 0.001516417f,
     0.684037639f,-0.158711173f, 0.050467793f,-0.012383903f, 0.001509769f,
     0.681587783f,-0.158525823f, 0.050400021f,-0.012357051f, 0.001503079f,
     0.679132597f,-0.158334650f, 0.050330342f,-0.012329751f, 0.001496347f,
     0.676672145f,-0.158137687f, 0.050258767f,-0.012302006f, 0.001489575f,
     0.674206487f,-0.157934966f, 0.050185310f,-0.012273821f, 0.001482764f,
     0.671735685f,-0.157726522f, 0.050109981f,-0.012245200f, 0.001475914f,
     0.669259802f,-0.157512387f, 0.050032793f,-0.012216147f, 0.001469026f,
     0.666778900f,-0.157292594f, 0.049953758f,-0.012186667f, 0.001462101f,
     0.664293039f,-0.157067178f, 0.049872888f,-0.012156762f, 0.001455141f,
     0.661802283f,-0.156836172f, 0.049790195f,-0.012126439f, 0.001448145f,
     0.659306693f,-0.156599609f, 0.049705692f,-0.012095699f, 0.001441115f,
     0.656806333f,-0.156357523f, 0.049619391f,-0.012064549f, 0.001434051f,
     0.654301263f,-0.156109948f, 0.049531303f,-0.012032992f, 0.001426955f,
     0.651791546f,-0.155856918f, 0.049441442f,-0.012001031f, 0.001419827f,
     0.649277246f,-0.155598467f, 0.049349819f,-0.011968672f, 0.001412668f,
     0.646758423f,-0.155334628f, 0.049256448f,-0.011935918f, 0.001405479f,
     0.644235142f,-0.155065436f, 0.049161340f,-0.011902774f, 0.001398261f,
     0.641707464f,-0.154790925f, 0.049064507f,-0.011869243f, 0.001391015f,
     0.639175452f,-0.154511129f, 0.048965963f,-0.011835330f, 0.001383741f,
     0.636639169f,-0.154226083f, 0.048865719f,-0.011801038f, 0.001376440f,
     0.634098677f,-0.153935820f, 0.048763788f,-0.011766373f, 0.001369113f,
     0.631554040f,-0.153640376f, 0.048660183f,-0.011731337f, 0.001361761f,
     0.629005320f,-0.153339784f, 0.048554915f,-0.011695936f, 0.001354384f,
     0.626452580f,-0.153034079f, 0.048447999f,-0.011660173f, 0.001346984f,
     0.623895883f,-0.152723296f, 0.048339445f,-0.011624053f, 0.001339561f,
     0.621335293f,-0.152407470f, 0.048229267f,-0.011587579f, 0.001332116f,
     0.618770871f,-0.152086634f, 0.048117478f,-0.011550756f, 0.001324650f,
     0.616202682f,-0.151760824f, 0.048004090f,-0.011513587f, 0.001317164f,
     0.613630788f,-0.151430075f, 0.047889115f,-0.011476077f, 0.001309657f,
     0.611055252f,-0.151094421f, 0.047772566f,-0.011438230f, 0.001302132f,
     0.608476138f,-0.150753897f, 0.047654456f,-0.011400050f, 0.001294589f,
     0.605893509f,-0.150408538f, 0.047534798f,-0.011361541f, 0.001287028f,
     0.603307427f,-0.150058380f, 0.047413604f,-0.011322706f, 0.001279451f,
     0.600717957f,-0.149703457f, 0.047290887f,-0.011283552f, 0.001271857f,
     0.598125161f,-0.149343804f, 0.047166660f,-0.011244080f, 0.001264249f,
     0.595529103f,-0.148979456f, 0.047040936f,-0.011204296f, 0.001256626f,
     0.592929846f,-0.148610450f, 0.046913726f,-0.011164202f, 0.001248990f,
     0.590327454f,-0.148236818f, 0.046785045f,-0.011123805f, 0.001241340f,
     0.587721989f,-0.147858598f, 0.046654904f,-0.011083106f, 0.001233679f,
     0.585113515f,-0.147475824f, 0.046523317f,-0.011042111f, 0.001226005f,
     0.582502096f,-0.147088532f, 0.046390297f,-0.011000824f, 0.001218321f,
     0.579887795f,-0.146696757f, 0.046255856f,-0.010959248f, 0.001210627f,
     0.577270674f,-0.146300533f, 0.046120007f,-0.010917387f, 0.001202924f,
     0.574650799f,-0.145899898f, 0.045982762f,-0.010875246f, 0.001195211f,
     0.572028231f,-0.145494885f, 0.045844136f,-0.010832828f, 0.001187491f,
     0.569403034f,-0.145085532f, 0.045704140f,-0.010790137f, 0.001179764f,
     0.566775272f,-0.144671872f, 0.045562787f,-0.010747178f, 0.001172030f,
     0.564145009f,-0.144253941f, 0.045420091f,-0.010703955f, 0.001164289f,
     0.561512306f,-0.143831776f, 0.045276064f,-0.010660470f, 0.001156544f,
     0.558877229f,-0.143405412f, 0.045130719f,-0.010616729f, 0.001148794f,
     0.556239839f,-0.142974883f, 0.044984069f,-0.010572735f, 0.001141040f,
     0.553600201f,-0.142540227f, 0.044836126f,-0.010528493f, 0.001133283f,
     0.550958378f,-0.142101478f, 0.044686904f,-0.010484005f, 0.001125523f,
     0.548314433f,-0.141658672f, 0.044536416f,-0.010439276f, 0.001117761f,
     0.545668429f,-0.141211844f, 0.044384675f,-0.010394310f, 0.001109997f,
     0.543020430f,-0.140761032f, 0.044231692f,-0.010349111f, 0.001102233f,
     0.540370499f,-0.140306269f, 0.044077482f,-0.010303683f, 0.001094469f,
     0.537718699f,-0.139847592f, 0.043922057f,-0.010258029f, 0.001086705f,
     0.535065094f,-0.139385036f, 0.043765430f,-0.010212153f, 0.001078942f,
     0.532409746f,-0.138918637f, 0.043607614f,-0.010166060f, 0.001071182f,
     0.529752718f,-0.138448432f, 0.043448622f,-0.010119753f, 0.001063423f,
     0.527094075f,-0.137974455f, 0.043288466f,-0.010073235f, 0.001055668f,
     0.524433878f,-0.137496742f, 0.043127159f,-0.010026512f, 0.001047916f,
     0.521772191f,-0.137015329f, 0.042964716f,-0.009979586f, 0.001040168f,
     0.519109077f,-0.136530252f, 0.042801147f,-0.009932461f, 0.001032425f,
     0.516444599f,-0.136041547f, 0.042636467f,-0.009885141f, 0.001024687f,
     0.513778819f,-0.135549248f, 0.042470687f,-0.009837631f, 0.001016955f,
     0.511111801f,-0.135053393f, 0.042303821f,-0.009789933f, 0.001009230f,
     0.508443608f,-0.134554017f, 0.042135882f,-0.009742051f, 0.001001511f,
     0.505774302f,-0.134051154f, 0.041966883f,-0.009693990f, 0.000993800f,
     0.503103946f,-0.133544842f, 0.041796836f,-0.009645752f, 0.000986098f,
     0.500432602f,-0.133035116f, 0.041625754f,-0.009597342f, 0.000978404f,
     0.497760334f,-0.132522012f, 0.041453650f,-0.009548764f, 0.000970719f,
     0.495087203f,-0.132005564f, 0.041280536f,-0.009500020f, 0.000963044f,
     0.492413273f,-0.131485810f, 0.041106427f,-0.009451116f, 0.000955380f,
     0.489738606f,-0.130962784f, 0.040931333f,-0.009402053f, 0.000947726f,
     0.487063264f,-0.130436523f, 0.040755269f,-0.009352837f, 0.000940083f,
     0.484387309f,-0.129907061f, 0.040578247f,-0.009303470f, 0.000932453f,
     0.481710804f,-0.129374435f, 0.040400279f,-0.009253957f, 0.000924835f,
     0.479033811f,-0.128838680f, 0.040221378f,-0.009204300f, 0.000917229f,
     0.476356392f,-0.128299831f, 0.040041558f,-0.009154505f, 0.000909637f,
     0.473678610f,-0.127757925f, 0.039860830f,-0.009104573f, 0.000902059f,
     0.471000525f,-0.127212997f, 0.039679208f,-0.009054509f, 0.000894496f,
     0.468322201f,-0.126665082f, 0.039496704f,-0.009004316f, 0.000886947f,
     0.465643698f,-0.126114216f, 0.039313331f,-0.008953998f, 0.000879414f,
     0.462965079f,-0.125560435f, 0.039129101f,-0.008903558f, 0.000871896f,
     0.460286405f,-0.125003773f, 0.038944027f,-0.008853000f, 0.000864395f,
     0.457607738f,-0.124444266f, 0.038758122f,-0.008802328f, 0.000856910f,
     0.454929140f,-0.123881950f, 0.038571399f,-0.008751544f, 0.000849443f,
     0.452250671f,-0.123316860f, 0.038383869f,-0.008700653f, 0.000841994f,
     0.449572393f,-0.122749031f, 0.038195545f,-0.008649657f, 0.000834562f,
     0.446894368f,-0.122178499f, 0.038006440f,-0.008598561f, 0.000827149f,
     0.444216656f,-0.121605299f, 0.037816567f,-0.008547367f, 0.000819755f,
     0.441539319f,-0.121029465f, 0.037625937f,-0.008496080f, 0.000812381f,
     0.438862417f,-0.120451035f, 0.037434564f,-0.008444702f, 0.000805026f,
     0.436186011f,-0.119870041f, 0.037242460f,-0.008393237f, 0.000797692f,
     0.433510163f,-0.119286520f, 0.037049637f,-0.008341688f, 0.000790378f,
     0.430834932f,-0.118700507f, 0.036856108f,-0.008290058f, 0.000783086f,
     0.428160380f,-0.118112036f, 0.036661885f,-0.008238352f, 0.000775815f,
     0.425486566f,-0.117521144f, 0.036466980f,-0.008186572f, 0.000768565f,
     0.422813551f,-0.116927863f, 0.036271406f,-0.008134722f, 0.000761339f,
     0.420141396f,-0.116332231f, 0.036075174f,-0.008082804f, 0.000754135f,
     0.417470160f,-0.115734281f, 0.035878299f,-0.008030823f, 0.000746954f,
     0.414799903f,-0.115134048f, 0.035680790f,-0.007978781f, 0.000739796f,
     0.412130686f,-0.114531567f, 0.035482662f,-0.007926681f, 0.000732662f,
     0.409462568f,-0.113926872f, 0.035283926f,-0.007874528f, 0.000725553f,
     0.406795609f,-0.113320000f, 0.035084593f,-0.007822324f, 0.000718468f,
     0.404129868f,-0.112710983f, 0.034884678f,-0.007770072f, 0.000711408f,
     0.401465405f,-0.112099857f, 0.034684190f,-0.007717775f, 0.000704373f,
     0.398802279f,-0.111486655f, 0.034483143f,-0.007665437f, 0.000697364f,
     0.396140548f,-0.110871414f, 0.034281549f,-0.007613061f, 0.000690381f,
     0.393480274f,-0.110254166f, 0.034079419f,-0.007560650f, 0.000683424f,
     0.390821513f,-0.109634947f, 0.033876767f,-0.007508207f, 0.000676494f,
     0.388164325f,-0.109013790f, 0.033673602f,-0.007455735f, 0.000669590f,
     0.385508769f,-0.108390730f, 0.033469939f,-0.007403238f, 0.000662714f,
     0.382854903f,-0.107765801f, 0.033265787f,-0.007350717f, 0.000655866f,
     0.380202785f,-0.107139037f, 0.033061161f,-0.007298177f, 0.000649046f,
     0.377552474f,-0.106510472f, 0.032856070f,-0.007245621f, 0.000642253f,
     0.374904028f,-0.105880140f, 0.032650528f,-0.007193050f, 0.000635490f,
     0.372257505f,-0.105248075f, 0.032444545f,-0.007140469f, 0.000628755f,
     0.369612962f,-0.104614312f, 0.032238134f,-0.007087881f, 0.000622049f,
     0.366970458f,-0.103978882f, 0.032031306f,-0.007035287f, 0.000615373f,
     0.364330050f,-0.103341821f, 0.031824073f,-0.006982692f, 0.000608726f,
     0.361691794f,-0.102703162f, 0.031616447f,-0.006930098f, 0.000602110f,
     0.359055750f,-0.102062939f, 0.031408439f,-0.006877508f, 0.000595523f,
     0.356421972f,-0.101421184f, 0.031200061f,-0.006824926f, 0.000588967f,
     0.353790520f,-0.100777932f, 0.030991325f,-0.006772353f, 0.000582442f,
     0.351161448f,-0.100133216f, 0.030782241f,-0.006719792f, 0.000575948f,
     0.348534815f,-0.099487069f, 0.030572821f,-0.006667247f, 0.000569485f,
     0.345910675f,-0.098839524f, 0.030363078f,-0.006614721f, 0.000563054f,
     0.343289087f,-0.098190615f, 0.030153021f,-0.006562215f, 0.000556654f,
     0.340670105f,-0.097540374f, 0.029942663f,-0.006509734f, 0.000550287f,
     0.338053786f,-0.096888834f, 0.029732015f,-0.006457279f, 0.000543951f,
     0.335440186f,-0.096236029f, 0.029521089f,-0.006404853f, 0.000537649f,
     0.332829360f,-0.095581991f, 0.029309894f,-0.006352460f, 0.000531378f,
     0.330221364f,-0.094926753f, 0.029098443f,-0.006300101f, 0.000525141f,
     0.327616253f,-0.094270347f, 0.028886747f,-0.006247780f, 0.000518937f,
     0.325014082f,-0.093612807f, 0.028674817f,-0.006195500f, 0.000512766f,
     0.322414906f,-0.092954163f, 0.028462663f,-0.006143262f, 0.000506629f,
     0.319818781f,-0.092294450f, 0.028250298f,-0.006091069f, 0.000500525f,
     0.317225760f,-0.091633699f, 0.028037732f,-0.006038925f, 0.000494456f,
     0.314635898f,-0.090971943f, 0.027824976f,-0.005986831f, 0.000488420f,
     0.312049250f,-0.090309213f, 0.027612040f,-0.005934790f, 0.000482419f,
     0.309465869f,-0.089645542f, 0.027398936f,-0.005882806f, 0.000476453f,
     0.306885810f,-0.088980961f, 0.027185675f,-0.005830879f, 0.000470521f,
     0.304309126f,-0.088315503f, 0.026972268f,-0.005779014f, 0.000464623f,
     0.301735870f,-0.087649199f, 0.026758724f,-0.005727211f, 0.000458761f,
     0.299166097f,-0.086982081f, 0.026545055f,-0.005675475f, 0.000452934f,
     0.296599859f,-0.086314180f, 0.026331272f,-0.005623807f, 0.000447143f,
     0.294037209f,-0.085645528f, 0.026117385f,-0.005572209f, 0.000441387f,
     0.291478200f,-0.084976157f, 0.025903405f,-0.005520685f, 0.000435666f,
     0.288922885f,-0.084306097f, 0.025689341f,-0.005469237f, 0.000429981f,
     0.286371316f,-0.083635380f, 0.025475206f,-0.005417866f, 0.000424332f,
     0.283823545f,-0.082964036f, 0.025261008f,-0.005366575f, 0.000418720f,
     0.281279624f,-0.082292098f, 0.025046759f,-0.005315368f, 0.000413143f,
     0.278739606f,-0.081619595f, 0.024832469f,-0.005264245f, 0.000407603f,
     0.276203542f,-0.080946559f, 0.024618148f,-0.005213209f, 0.000402099f,
     0.273671482f,-0.080273020f, 0.024403807f,-0.005162263f, 0.000396632f,
     0.271143479f,-0.079599009f, 0.024189455f,-0.005111409f, 0.000391201f,
     0.268619584f,-0.078924556f, 0.023975103f,-0.005060649f, 0.000385807f,
     0.266099847f,-0.078249692f, 0.023760760f,-0.005009985f, 0.000380450f,
     0.263584318f,-0.077574447f, 0.023546438f,-0.004959420f, 0.000375130f,
     0.261073049f,-0.076898851f, 0.023332145f,-0.004908956f, 0.000369847f,
     0.258566090f,-0.076222934f, 0.023117893f,-0.004858594f, 0.000364602f,
     0.256063490f,-0.075546727f, 0.022903690f,-0.004808337f, 0.000359393f,
     0.253565299f,-0.074870258f, 0.022689547f,-0.004758188f, 0.000354222f,
     0.251071568f,-0.074193558f, 0.022475473f,-0.004708148f, 0.000349088f,
     0.248582344f,-0.073516656f, 0.022261479f,-0.004658219f, 0.000343992f,
     0.246097678f,-0.072839582f, 0.022047574f,-0.004608404f, 0.000338934f,
     0.243617618f,-0.072162365f, 0.021833767f,-0.004558704f, 0.000333913f,
     0.241142213f,-0.071485035f, 0.021620069f,-0.004509122f, 0.000328930f,
     0.238671511f,-0.070807621f, 0.021406488f,-0.004459659f, 0.000323984f,
     0.236205561f,-0.070130151f, 0.021193035f,-0.004410318f, 0.000319077f,
     0.233744411f,-0.069452655f, 0.020979718f,-0.004361100f, 0.000314207f,
     0.231288109f,-0.068775161f, 0.020766548f,-0.004312008f, 0.000309375f,
     0.228836701f,-0.068097699f, 0.020553533f,-0.004263043f, 0.000304582f,
     0.226390237f,-0.067420297f, 0.020340683f,-0.004214207f, 0.000299826f,
     0.223948762f,-0.066742982f, 0.020128008f,-0.004165503f, 0.000295108f,
     0.221512323f,-0.066065785f, 0.019915515f,-0.004116932f, 0.000290429f,
     0.219080968f,-0.065388732f, 0.019703215f,-0.004068496f, 0.000285787f,
     0.216654743f,-0.064711852f, 0.019491117f,-0.004020196f, 0.000281184f,
     0.214233694f,-0.064035173f, 0.019279229f,-0.003972036f, 0.000276619f,
     0.211817866f,-0.063358724f, 0.019067561f,-0.003924015f, 0.000272092f,
     0.209407307f,-0.062682530f, 0.018856122f,-0.003876137f, 0.000267604f,
     0.207002061f,-0.062006621f, 0.018644920f,-0.003828403f, 0.000263153f,
     0.204602173f,-0.061331024f, 0.018433965f,-0.003780814f, 0.000258741f,
     0.202207689f,-0.060655766f, 0.018223264f,-0.003733373f, 0.000254367f,
     0.199818654f,-0.059980874f, 0.018012827f,-0.003686081f, 0.000250032f,
     0.197435111f,-0.059306375f, 0.017802663f,-0.003638940f, 0.000245734f,
     0.195057107f,-0.058632298f, 0.017592780f,-0.003591951f, 0.000241475f,
     0.192684683f,-0.057958667f, 0.017383186f,-0.003545116f, 0.000237254f,
     0.190317885f,-0.057285511f, 0.017173891f,-0.003498437f, 0.000233071f,
     0.187956756f,-0.056612855f, 0.016964902f,-0.003451915f, 0.000228927f,
     0.185601339f,-0.055940727f, 0.016756228f,-0.003405553f, 0.000224821f,
     0.183251678f,-0.055269152f, 0.016547878f,-0.003359350f, 0.000220752f,
     0.180907815f,-0.054598157f, 0.016339859f,-0.003313310f, 0.000216722f,
     0.178569792f,-0.053927768f, 0.016132180f,-0.003267434f, 0.000212731f,
     0.176237654f,-0.053258011f, 0.015924850f,-0.003221722f, 0.000208777f,
     0.173911440f,-0.052588912f, 0.015717875f,-0.003176177f, 0.000204861f,
     0.171591194f,-0.051920496f, 0.015511264f,-0.003130800f, 0.000200983f,
     0.169276957f,-0.051252790f, 0.015305026f,-0.003085592f, 0.000197143f,
     0.166968771f,-0.050585817f, 0.015099168f,-0.003040555f, 0.000193341f,
     0.164666676f,-0.049919605f, 0.014893698f,-0.002995691f, 0.000189577f,
     0.162370713f,-0.049254177f, 0.014688624f,-0.002951000f, 0.000185851f,
     0.160080923f,-0.048589560f, 0.014483954f,-0.002906485f, 0.000182163f,
     0.157797346f,-0.047925777f, 0.014279695f,-0.002862145f, 0.000178512f,
     0.155520023f,-0.047262854f, 0.014075855f,-0.002817984f, 0.000174899f,
     0.153248993f,-0.046600815f, 0.013872442f,-0.002774001f, 0.000171324f,
     0.150984296f,-0.045939685f, 0.013669462f,-0.002730199f, 0.000167786f,
     0.148725971f,-0.045279488f, 0.013466925f,-0.002686579f, 0.000164285f,
     0.146474057f,-0.044620249f, 0.013264837f,-0.002643141f, 0.000160822f,
     0.144228593f,-0.043961991f, 0.013063205f,-0.002599888f, 0.000157396f,
     0.141989618f,-0.043304738f, 0.012862038f,-0.002556820f, 0.000154008f,
     0.139757169f,-0.042648514f, 0.012661341f,-0.002513938f, 0.000150656f,
     0.137531285f,-0.041993344f, 0.012461123f,-0.002471244f, 0.000147342f,
     0.135312004f,-0.041339249f, 0.012261390f,-0.002428739f, 0.000144064f,
     0.133099362f,-0.040686254f, 0.012062150f,-0.002386425f, 0.000140824f,
     0.130893398f,-0.040034383f, 0.011863409f,-0.002344301f, 0.000137620f,
     0.128694148f,-0.039383657f, 0.011665175f,-0.002302370f, 0.000134453f,
     0.126501649f,-0.038734100f, 0.011467454f,-0.002260631f, 0.000131323f,
     0.124315937f,-0.038085735f, 0.011270254f,-0.002219088f, 0.000128229f,
     0.122137048f,-0.037438584f, 0.011073581f,-0.002177740f, 0.000125171f,
     0.119965018f,-0.036792671f, 0.010877441f,-0.002136588f, 0.000122150f,
     0.117799883f,-0.036148017f, 0.010681842f,-0.002095634f, 0.000119165f,
     0.115641679f,-0.035504644f, 0.010486791f,-0.002054878f, 0.000116216f,
     0.113490439f,-0.034862575f, 0.010292293f,-0.002014322f, 0.000113304f,
     0.111346199f,-0.034221832f, 0.010098355f,-0.001973967f, 0.000110427f,
     0.109208994f,-0.033582436f, 0.009904984f,-0.001933813f, 0.000107585f,
     0.107078857f,-0.032944409f, 0.009712186f,-0.001893861f, 0.000104780f,
     0.104955823f,-0.032307773f, 0.009519967f,-0.001854112f, 0.000102010f,
     0.102839925f,-0.031672548f, 0.009328334f,-0.001814568f, 0.000099275f,
     0.100731196f,-0.031038757f, 0.009137293f,-0.001775228f, 0.000096576f,
     0.098629671f,-0.030406420f, 0.008946849f,-0.001736095f, 0.000093911f,
     0.096535380f,-0.029775558f, 0.008757010f,-0.001697168f, 0.000091282f,
     0.094448358f,-0.029146192f, 0.008567781f,-0.001658448f, 0.000088688f,
     0.092368636f,-0.028518343f, 0.008379168f,-0.001619937f, 0.000086128f,
     0.090296247f,-0.027892030f, 0.008191177f,-0.001581635f, 0.000083603f,
     0.088231221f,-0.027267275f, 0.008003813f,-0.001543542f, 0.000081113f,
     0.086173591f,-0.026644097f, 0.007817084f,-0.001505661f, 0.000078656f,
     0.084123388f,-0.026022517f, 0.007630993f,-0.001467990f, 0.000076234f,
     0.082080642f,-0.025402554f, 0.007445548f,-0.001430532f, 0.000073846f,
     0.080045384f,-0.024784228f, 0.007260753f,-0.001393286f, 0.000071492f,
     0.078017645f,-0.024167559f, 0.007076615f,-0.001356254f, 0.000069172f,
     0.075997454f,-0.023552566f, 0.006893138f,-0.001319435f, 0.000066885f,
     0.073984841f,-0.022939269f, 0.006710328f,-0.001282832f, 0.000064632f,
     0.071979836f,-0.022327686f, 0.006528191f,-0.001246443f, 0.000062412f,
     0.069982467f,-0.021717836f, 0.006346731f,-0.001210271f, 0.000060225f,
     0.067992764f,-0.021109739f, 0.006165955f,-0.001174315f, 0.000058072f,
     0.066010755f,-0.020503413f, 0.005985866f,-0.001138576f, 0.000055951f,
     0.064036468f,-0.019898876f, 0.005806472f,-0.001103055f, 0.000053862f,
     0.062069932f,-0.019296147f, 0.005627775f,-0.001067751f, 0.000051807f,
     0.060111174f,-0.018695244f, 0.005449782f,-0.001032667f, 0.000049783f,
     0.058160222f,-0.018096185f, 0.005272497f,-0.000997801f, 0.000047792f,
     0.056217102f,-0.017498988f, 0.005095926f,-0.000963156f, 0.000045833f,
     0.054281842f,-0.016903671f, 0.004920073f,-0.000928730f, 0.000043905f,
     0.052354468f,-0.016310251f, 0.004744943f,-0.000894525f, 0.000042010f,
     0.050435006f,-0.015718746f, 0.004570540f,-0.000860541f, 0.000040146f,
     0.048523483f,-0.015129173f, 0.004396870f,-0.000826779f, 0.000038313f,
     0.046619924f,-0.014541549f, 0.004223937f,-0.000793238f, 0.000036511f,
     0.044724355f,-0.013955892f, 0.004051745f,-0.000759920f, 0.000034740f,
     0.042836800f,-0.013372217f, 0.003880299f,-0.000726824f, 0.000033000f,
     0.040957285f,-0.012790543f, 0.003709604f,-0.000693951f, 0.000031291f,
     0.039085833f,-0.012210884f, 0.003539663f,-0.000661301f, 0.000029612f,
     0.037222470f,-0.011633259f, 0.003370481f,-0.000628876f, 0.000027964f,
     0.035367219f,-0.011057682f, 0.003202062f,-0.000596674f, 0.000026345f,
     0.033520103f,-0.010484170f, 0.003034411f,-0.000564696f, 0.000024756f,
     0.031681147f,-0.009912739f, 0.002867532f,-0.000532943f, 0.000023197f,
     0.029850373f,-0.009343404f, 0.002701428f,-0.000501414f, 0.000021668f,
     0.028027804f,-0.008776182f, 0.002536104f,-0.000470111f, 0.000020168f,
     0.026213462f,-0.008211087f, 0.002371564f,-0.000439032f, 0.000018697f,
     0.024407370f,-0.007648135f, 0.002207811f,-0.000408180f, 0.000017255f,
     0.022609549f,-0.007087341f, 0.002044849f,-0.000377553f, 0.000015842f,
     0.020820021f,-0.006528720f, 0.001882682f,-0.000347151f, 0.000014457f,
     0.019038808f,-0.005972286f, 0.001721315f,-0.000316976f, 0.000013101f,
     0.017265930f,-0.005418056f, 0.001560750f,-0.000287027f, 0.000011773f,
     0.015501408f,-0.004866042f, 0.001400991f,-0.000257305f, 0.000010473f,
     0.013745262f,-0.004316260f, 0.001242041f,-0.000227808f, 0.000009201f,
     0.011997513f,-0.003768723f, 0.001083905f,-0.000198539f, 0.000007956f,
     0.010258180f,-0.003223445f, 0.000926585f,-0.000169495f, 0.000006739f,
     0.008527283f,-0.002680442f, 0.000770086f,-0.000140679f, 0.000005549f,
     0.006804842f,-0.002139725f, 0.000614409f,-0.000112090f, 0.000004386f,
     0.005090874f,-0.001601309f, 0.000459559f,-0.000083727f, 0.000003250f,
     0.003385399f,-0.001065208f, 0.000305539f,-0.000055591f, 0.000002140f,
     0.001688435f,-0.000531434f, 0.000152351f,-0.000027682f, 0.000001057f,
};
