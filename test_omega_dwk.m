clear;
clf;

data=[0.01	0.002	0.0216113803299	6.06065616063e-05
0.0194949494949	0.002	0.021505858093	6.06849344998e-05
0.0289898989899	0.002	0.021392114215	6.06506079854e-05
0.0384848484848	0.002	0.0212690294935	6.04688885428e-05
0.0479797979798	0.002	0.0211352154951	6.00894105481e-05
0.0574747474747	0.002	0.0209888942716	5.94339662789e-05
0.0669696969697	0.002	0.0208276761668	5.83677012424e-05
0.0764646464646	0.002	0.0206480717401	5.66122910855e-05
0.0859595959596	0.002	0.020444035833	5.33392651035e-05
0.0954545454545	0.002	0.0201987437243	4.04049698498e-05
0.104949494949	0.002	0.0199015401061	-2.39364684689e-05
0.114444444444	0.002	0.019691341571	-0.000152736272447
0.123939393939	0.002	0.0193840543702	-9.61682087019e-05
0.133434343434	0.002	0.0189753331958	-0.000323431944937
0.142929292929	0.002	0.0186781882321	-0.00028980744402
0.152424242424	0.002	0.018465137697	-0.000759512562476
0.161919191919	0.002	0.0177249365928	-0.00100578639273
0.171414141414	0.002	0.0174200396997	-0.000993259942416
0.180909090909	0.002	0.0169074963681	-0.00161066907858
0.190404040404	0.002	0.0163781283617	-0.0022201688616
0.199898989899	0.002	0.0163024332626	-0.00230321797632
0.209393939394	0.002	0.0163152478759	-0.00261840272004
0.218888888889	0.002	0.0154733361771	-0.00401252941389
0.228383838384	0.002	0.0154641002684	-0.00434057746838
0.237878787879	0.002	0.0149406603364	-0.0057440272763
0.247373737374	0.002	0.0141933900533	-0.00633848568711
0.256868686869	0.002	0.014004328674	-0.00692381794569
0.266363636364	0.002	0.0139831460013	-0.00783153293342
0.275858585859	0.002	0.0140523391246	-0.00902543223477
0.285353535354	0.002	0.0144539614384	-0.0104332923239
0.294848484848	0.002	0.0153514958227	-0.0115790364888
0.304343434343	0.002	0.0160908144156	-0.0122598502855
0.313838383838	0.002	0.0169596535577	-0.0129495711445
0.323333333333	0.002	0.0170304076526	-0.012872082974
0.332828282828	0.002	0.0165775126131	-0.0146410427092
0.342323232323	0.002	0.0184031495624	-0.0165977345334
0.351818181818	0.002	0.0200533976232	-0.0162888872088
0.361313131313	0.002	0.0193329283158	-0.0168184466101
0.370808080808	0.002	0.0215872554397	-0.0189592294376
0.380303030303	0.002	0.0226456587359	-0.0178164549468
0.389797979798	0.002	0.023209771542	-0.0201739075079
0.399292929293	0.002	0.0253668306689	-0.0190245146201
0.408787878788	0.002	0.0259089885286	-0.0210538763795
0.418282828283	0.002	0.0275838743848	-0.0196336148205
0.427777777778	0.002	0.0295099632133	-0.0213692929903
0.437272727273	0.002	0.029667691818	-0.0207156674682
0.446767676768	0.002	0.0323707766697	-0.020211848598
0.456262626263	0.002	0.0338536296995	-0.0212773230778
0.465757575758	0.002	0.0343942503414	-0.020857017746
0.475252525253	0.002	0.0360746688325	-0.0197574020337
0.484747474747	0.002	0.0382400217681	-0.0193233469235
0.494242424242	0.002	0.0399789784738	-0.0192421079732
0.503737373737	0.002	0.041326439441	-0.0189325103195
0.513232323232	0.002	0.0426013157985	-0.0182813633133
0.522727272727	0.002	0.0439439335886	-0.0174127286117
0.532222222222	0.002	0.045349797948	-0.0164210695322
0.541717171717	0.002	0.0467837783174	-0.01533243149
0.551212121212	0.002	0.0482138503262	-0.0141330581482
0.560707070707	0.002	0.0496021375406	-0.0127983862963
0.570202020202	0.002	0.0508960121977	-0.011325825655
0.579696969697	0.002	0.0520534804504	-0.00976345898505
0.589191919192	0.002	0.0531051931331	-0.00819018021377
0.598686868687	0.002	0.0541623819984	-0.0066018912625
0.608181818182	0.002	0.055253521693	-0.004861661754156
0.617676767677	0.002	0.0562270727184	-0.00291712734682
0.627171717172	0.002	0.057029551575	-0.000905938252728
0.636666666667	0.002	0.0577901201963	0.00113789997686
0.646161616162	0.002	0.0584915530801	0.00335437630176
0.655656565657	0.002	0.0590080899239	0.00566964779714
0.665151515152	0.002	0.0594746870967	0.00803990478383
0.674646464646	0.002	0.0597772003301	0.0105865777448
0.684141414141	0.002	0.0599743022299	0.013156427085
0.693636363636	0.002	0.059993859093	0.0159062041502
0.703131313131	0.002	0.0599136120285	0.0187006141022
0.712626262626	0.002	0.0595954636812	0.0216190956484
0.722121212121	0.002	0.059154388114	0.0246736324475
0.731616161616	0.002	0.0585161641213	0.0277743280527
0.741111111111	0.002	0.0576234578656	0.0309985280365
0.750606060606	0.002	0.0565206322842	0.0343581913239
0.760101010101	0.002	0.0551938823104	0.0378103545592
0.769595959596	0.002	0.0535911929238	0.0413459052378
0.779090909091	0.002	0.0516758390968	0.0449813227762
0.788585858586	0.002	0.0494242136422	0.0487257728189
0.798080808081	0.002	0.0468078327945	0.0525783724029
0.807575757576	0.002	0.0437879084747	0.0565357176863
0.817070707071	0.002	0.0403158802639	0.0605956156517
0.826565656566	0.002	0.0363327041227	0.0647574427822
0.836060606061	0.002	0.0317654020493	0.0690209262622
0.845555555556	0.002	0.026522487105	0.0733825717656
0.855050505051	0.002	0.020492919185	0.0778306397661
0.864545454545	0.002	0.0135495865716	0.0823488977724
0.87404040404	0.002	0.0055354222435	0.0869366306686
0.883535353535	0.002	-0.00378806751475	0.0916079674004
0.89303030303	0.002	-0.0147715990565	0.0963319560192
0.902525252525	0.002	-0.0278285392516	0.101035812768
0.91202020202	0.002	-0.0435677199838	0.105717021685
0.921515151515	0.002	-0.0630278211944	0.110277952506
0.93101010101	0.002	-0.0877229494603	0.114511223526
0.940505050505	0.002	-0.120443914643	0.118131419748
0.95	0.002	-0.166527040708	0.120234459356];


plot(data(:,1),data(:,3));