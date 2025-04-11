#include "gtest/gtest.h"
#include <cstdint>
#include <stdexcept>

#include "../src/SpreadsheetCellCoordinates.h"

TEST(SpreadsheetCellCoordinates,Constructor_invalid_argument_exception_with_0_as_column_index) {
    const std::size_t rowMaxIndex = 20;
    for (std::size_t j = 1; j <= rowMaxIndex; ++j) {
        const auto rowIndex = j;
        bool exceptionThrown = false;
        try {
            SpreadsheetCellCoordinates coordinates(0,j);
        }
        catch (const std::invalid_argument& e) {
            exceptionThrown = true;
        }
        EXPECT_TRUE(exceptionThrown);
    }
}

TEST(SpreadsheetCellCoordinates,Constructor_invalid_argument_exception_with_0_as_row_index) {
    const std::size_t columnMaxIndex = 20;
    for (std::size_t i = 1; i <= columnMaxIndex; ++i) {
        const auto columnIndex = i;
        bool exceptionThrown = false;
        try {
            SpreadsheetCellCoordinates coordinates(i,0);
        }
        catch (const std::invalid_argument& e) {
            exceptionThrown = true;
        }
        EXPECT_TRUE(exceptionThrown);
    }
}

TEST(SpreadsheetCellCoordinates,Constructor_string_column_version__first_53_columns) {
    const std::size_t rowMaxIndex = 20;
    for (std::size_t j = 1; j <= rowMaxIndex; ++j) {
        const auto rowIndex = j;

        const SpreadsheetCellCoordinates A("A",rowIndex);
        EXPECT_EQ(A.getColumnIndexAsString(),std::string("A"));

        const SpreadsheetCellCoordinates B("B",rowIndex);
        EXPECT_EQ(B.getColumnIndexAsString(),std::string("B"));

        const SpreadsheetCellCoordinates C("C",rowIndex);
        EXPECT_EQ(C.getColumnIndexAsString(),std::string("C"));

        const SpreadsheetCellCoordinates D("D",rowIndex);
        EXPECT_EQ(D.getColumnIndexAsString(),std::string("D"));

        const SpreadsheetCellCoordinates E("E",rowIndex);
        EXPECT_EQ(E.getColumnIndexAsString(),std::string("E"));

        const SpreadsheetCellCoordinates F("F",rowIndex);
        EXPECT_EQ(F.getColumnIndexAsString(),std::string("F"));

        const SpreadsheetCellCoordinates G("G",rowIndex);
        EXPECT_EQ(G.getColumnIndexAsString(),std::string("G"));

        const SpreadsheetCellCoordinates H("H",rowIndex);
        EXPECT_EQ(H.getColumnIndexAsString(),std::string("H"));

        const SpreadsheetCellCoordinates I("I",rowIndex);
        EXPECT_EQ(I.getColumnIndexAsString(),std::string("I"));

        const SpreadsheetCellCoordinates J("J",rowIndex);
        EXPECT_EQ(J.getColumnIndexAsString(),std::string("J"));

        const SpreadsheetCellCoordinates K("K",rowIndex);
        EXPECT_EQ(K.getColumnIndexAsString(),std::string("K"));

        const SpreadsheetCellCoordinates L("L",rowIndex);
        EXPECT_EQ(L.getColumnIndexAsString(),std::string("L"));

        const SpreadsheetCellCoordinates M("M",rowIndex);
        EXPECT_EQ(M.getColumnIndexAsString(),std::string("M"));

        const SpreadsheetCellCoordinates N("N",rowIndex);
        EXPECT_EQ(N.getColumnIndexAsString(),std::string("N"));

        const SpreadsheetCellCoordinates O("O",rowIndex);
        EXPECT_EQ(O.getColumnIndexAsString(),std::string("O"));

        const SpreadsheetCellCoordinates P("P",rowIndex);
        EXPECT_EQ(P.getColumnIndexAsString(),std::string("P"));

        const SpreadsheetCellCoordinates Q("Q",rowIndex);
        EXPECT_EQ(Q.getColumnIndexAsString(),std::string("Q"));

        const SpreadsheetCellCoordinates R("R",rowIndex);
        EXPECT_EQ(R.getColumnIndexAsString(),std::string("R"));

        const SpreadsheetCellCoordinates S("S",rowIndex);
        EXPECT_EQ(S.getColumnIndexAsString(),std::string("S"));

        const SpreadsheetCellCoordinates T("T",rowIndex);
        EXPECT_EQ(T.getColumnIndexAsString(),std::string("T"));

        const SpreadsheetCellCoordinates U("U",rowIndex);
        EXPECT_EQ(U.getColumnIndexAsString(),std::string("U"));

        const SpreadsheetCellCoordinates V("V",rowIndex);
        EXPECT_EQ(V.getColumnIndexAsString(),std::string("V"));

        const SpreadsheetCellCoordinates W("W",rowIndex);
        EXPECT_EQ(W.getColumnIndexAsString(),std::string("W"));

        const SpreadsheetCellCoordinates X("X",rowIndex);
        EXPECT_EQ(X.getColumnIndexAsString(),std::string("X"));

        const SpreadsheetCellCoordinates Y("Y",rowIndex);
        EXPECT_EQ(Y.getColumnIndexAsString(),std::string("Y"));

        const SpreadsheetCellCoordinates Z("Z",rowIndex);
        EXPECT_EQ(Z.getColumnIndexAsString(),std::string("Z"));

        const SpreadsheetCellCoordinates AA("AA",rowIndex);
        EXPECT_EQ(AA.getColumnIndexAsString(),std::string("AA"));

        const SpreadsheetCellCoordinates AB("AB",rowIndex);
        EXPECT_EQ(AB.getColumnIndexAsString(),std::string("AB"));

        const SpreadsheetCellCoordinates AC("AC",rowIndex);
        EXPECT_EQ(AC.getColumnIndexAsString(),std::string("AC"));

        const SpreadsheetCellCoordinates AD("AD",rowIndex);
        EXPECT_EQ(AD.getColumnIndexAsString(),std::string("AD"));

        const SpreadsheetCellCoordinates AE("AE",rowIndex);
        EXPECT_EQ(AE.getColumnIndexAsString(),std::string("AE"));

        const SpreadsheetCellCoordinates AF("AF",rowIndex);
        EXPECT_EQ(AF.getColumnIndexAsString(),std::string("AF"));

        const SpreadsheetCellCoordinates AG("AG",rowIndex);
        EXPECT_EQ(AG.getColumnIndexAsString(),std::string("AG"));

        const SpreadsheetCellCoordinates AH("AH",rowIndex);
        EXPECT_EQ(AH.getColumnIndexAsString(),std::string("AH"));

        const SpreadsheetCellCoordinates AI("AI",rowIndex);
        EXPECT_EQ(AI.getColumnIndexAsString(),std::string("AI"));

        const SpreadsheetCellCoordinates AJ("AJ",rowIndex);
        EXPECT_EQ(AJ.getColumnIndexAsString(),std::string("AJ"));

        const SpreadsheetCellCoordinates AK("AK",rowIndex);
        EXPECT_EQ(AK.getColumnIndexAsString(),std::string("AK"));

        const SpreadsheetCellCoordinates AL("AL",rowIndex);
        EXPECT_EQ(AL.getColumnIndexAsString(),std::string("AL"));

        const SpreadsheetCellCoordinates AM("AM",rowIndex);
        EXPECT_EQ(AM.getColumnIndexAsString(),std::string("AM"));

        const SpreadsheetCellCoordinates AN("AN",rowIndex);
        EXPECT_EQ(AN.getColumnIndexAsString(),std::string("AN"));

        const SpreadsheetCellCoordinates AO("AO",rowIndex);
        EXPECT_EQ(AO.getColumnIndexAsString(),std::string("AO"));

        const SpreadsheetCellCoordinates AP("AP",rowIndex);
        EXPECT_EQ(AP.getColumnIndexAsString(),std::string("AP"));

        const SpreadsheetCellCoordinates AQ("AQ",rowIndex);
        EXPECT_EQ(AQ.getColumnIndexAsString(),std::string("AQ"));

        const SpreadsheetCellCoordinates AR("AR",rowIndex);
        EXPECT_EQ(AR.getColumnIndexAsString(),std::string("AR"));

        const SpreadsheetCellCoordinates AS("AS",rowIndex);
        EXPECT_EQ(AS.getColumnIndexAsString(),std::string("AS"));

        const SpreadsheetCellCoordinates AT("AT",rowIndex);
        EXPECT_EQ(AT.getColumnIndexAsString(),std::string("AT"));

        const SpreadsheetCellCoordinates AU("AU",rowIndex);
        EXPECT_EQ(AU.getColumnIndexAsString(),std::string("AU"));

        const SpreadsheetCellCoordinates AV("AV",rowIndex);
        EXPECT_EQ(AV.getColumnIndexAsString(),std::string("AV"));

        const SpreadsheetCellCoordinates AW("AW",rowIndex);
        EXPECT_EQ(AW.getColumnIndexAsString(),std::string("AW"));

        const SpreadsheetCellCoordinates AX("AX",rowIndex);
        EXPECT_EQ(AX.getColumnIndexAsString(),std::string("AX"));

        const SpreadsheetCellCoordinates AY("AY",rowIndex);
        EXPECT_EQ(AY.getColumnIndexAsString(),std::string("AY"));

        const SpreadsheetCellCoordinates AZ("AZ",rowIndex);
        EXPECT_EQ(AZ.getColumnIndexAsString(),std::string("AZ"));

        const SpreadsheetCellCoordinates BA("BA",rowIndex);
        EXPECT_EQ(BA.getColumnIndexAsString(),std::string("BA"));
    }
}

TEST(SpreadsheetCellCoordinates,getRowIndex) {
    const std::size_t columnMaxIndex = 20;
    const std::size_t rowMaxIndex = 20;
    for (std::size_t i = 1; i <= columnMaxIndex; ++i) {
        const auto columnIndex = i;
        for (std::size_t j = 1; j <= rowMaxIndex; ++j) {
            const auto rowIndex = j;
            const SpreadsheetCellCoordinates coordinates(columnIndex,rowIndex);
            EXPECT_EQ(coordinates.getRowIndex(),rowIndex);
        }
    }
}

TEST(SpreadsheetCellCoordinates,getColumnIndexAsInteger) {
    const std::size_t columnMaxIndex = 20;
    const std::size_t rowMaxIndex = 20;
    for (std::size_t i = 1; i <= columnMaxIndex; ++i) {
        const auto columnIndex = i;
        for (std::size_t j = 1; j <= rowMaxIndex; ++j) {
            const auto rowIndex = j;
            const SpreadsheetCellCoordinates coordinates(columnIndex,rowIndex);
            EXPECT_EQ(coordinates.getColumnIndexAsInteger(),columnIndex);
        }
    }
}

TEST(SpreadsheetCellCoordinates,getColumnIndexAsString_first_53_columns) {
    const std::size_t rowMaxIndex = 20;
    for (std::size_t j = 1; j <= rowMaxIndex; ++j) {
        const auto rowIndex = j;

        const SpreadsheetCellCoordinates A(1,rowIndex);
        EXPECT_EQ(A.getColumnIndexAsString(),std::string("A"));

        const SpreadsheetCellCoordinates B(2,rowIndex);
        EXPECT_EQ(B.getColumnIndexAsString(),std::string("B"));

        const SpreadsheetCellCoordinates C(3,rowIndex);
        EXPECT_EQ(C.getColumnIndexAsString(),std::string("C"));

        const SpreadsheetCellCoordinates D(4,rowIndex);
        EXPECT_EQ(D.getColumnIndexAsString(),std::string("D"));

        const SpreadsheetCellCoordinates E(5,rowIndex);
        EXPECT_EQ(E.getColumnIndexAsString(),std::string("E"));

        const SpreadsheetCellCoordinates F(6,rowIndex);
        EXPECT_EQ(F.getColumnIndexAsString(),std::string("F"));

        const SpreadsheetCellCoordinates G(7,rowIndex);
        EXPECT_EQ(G.getColumnIndexAsString(),std::string("G"));

        const SpreadsheetCellCoordinates H(8,rowIndex);
        EXPECT_EQ(H.getColumnIndexAsString(),std::string("H"));

        const SpreadsheetCellCoordinates I(9,rowIndex);
        EXPECT_EQ(I.getColumnIndexAsString(),std::string("I"));

        const SpreadsheetCellCoordinates J(10,rowIndex);
        EXPECT_EQ(J.getColumnIndexAsString(),std::string("J"));

        const SpreadsheetCellCoordinates K(11,rowIndex);
        EXPECT_EQ(K.getColumnIndexAsString(),std::string("K"));

        const SpreadsheetCellCoordinates L(12,rowIndex);
        EXPECT_EQ(L.getColumnIndexAsString(),std::string("L"));

        const SpreadsheetCellCoordinates M(13,rowIndex);
        EXPECT_EQ(M.getColumnIndexAsString(),std::string("M"));

        const SpreadsheetCellCoordinates N(14,rowIndex);
        EXPECT_EQ(N.getColumnIndexAsString(),std::string("N"));

        const SpreadsheetCellCoordinates O(15,rowIndex);
        EXPECT_EQ(O.getColumnIndexAsString(),std::string("O"));

        const SpreadsheetCellCoordinates P(16,rowIndex);
        EXPECT_EQ(P.getColumnIndexAsString(),std::string("P"));

        const SpreadsheetCellCoordinates Q(17,rowIndex);
        EXPECT_EQ(Q.getColumnIndexAsString(),std::string("Q"));

        const SpreadsheetCellCoordinates R(18,rowIndex);
        EXPECT_EQ(R.getColumnIndexAsString(),std::string("R"));

        const SpreadsheetCellCoordinates S(19,rowIndex);
        EXPECT_EQ(S.getColumnIndexAsString(),std::string("S"));

        const SpreadsheetCellCoordinates T(20,rowIndex);
        EXPECT_EQ(T.getColumnIndexAsString(),std::string("T"));

        const SpreadsheetCellCoordinates U(21,rowIndex);
        EXPECT_EQ(U.getColumnIndexAsString(),std::string("U"));

        const SpreadsheetCellCoordinates V(22,rowIndex);
        EXPECT_EQ(V.getColumnIndexAsString(),std::string("V"));

        const SpreadsheetCellCoordinates W(23,rowIndex);
        EXPECT_EQ(W.getColumnIndexAsString(),std::string("W"));

        const SpreadsheetCellCoordinates X(24,rowIndex);
        EXPECT_EQ(X.getColumnIndexAsString(),std::string("X"));

        const SpreadsheetCellCoordinates Y(25,rowIndex);
        EXPECT_EQ(Y.getColumnIndexAsString(),std::string("Y"));

        const SpreadsheetCellCoordinates Z(26,rowIndex);
        EXPECT_EQ(Z.getColumnIndexAsString(),std::string("Z"));

        const SpreadsheetCellCoordinates AA(27,rowIndex);
        EXPECT_EQ(AA.getColumnIndexAsString(),std::string("AA"));

        const SpreadsheetCellCoordinates AB(28,rowIndex);
        EXPECT_EQ(AB.getColumnIndexAsString(),std::string("AB"));

        const SpreadsheetCellCoordinates AC(29,rowIndex);
        EXPECT_EQ(AC.getColumnIndexAsString(),std::string("AC"));

        const SpreadsheetCellCoordinates AD(30,rowIndex);
        EXPECT_EQ(AD.getColumnIndexAsString(),std::string("AD"));

        const SpreadsheetCellCoordinates AE(31,rowIndex);
        EXPECT_EQ(AE.getColumnIndexAsString(),std::string("AE"));

        const SpreadsheetCellCoordinates AF(32,rowIndex);
        EXPECT_EQ(AF.getColumnIndexAsString(),std::string("AF"));

        const SpreadsheetCellCoordinates AG(33,rowIndex);
        EXPECT_EQ(AG.getColumnIndexAsString(),std::string("AG"));

        const SpreadsheetCellCoordinates AH(34,rowIndex);
        EXPECT_EQ(AH.getColumnIndexAsString(),std::string("AH"));

        const SpreadsheetCellCoordinates AI(35,rowIndex);
        EXPECT_EQ(AI.getColumnIndexAsString(),std::string("AI"));

        const SpreadsheetCellCoordinates AJ(36,rowIndex);
        EXPECT_EQ(AJ.getColumnIndexAsString(),std::string("AJ"));

        const SpreadsheetCellCoordinates AK(37,rowIndex);
        EXPECT_EQ(AK.getColumnIndexAsString(),std::string("AK"));

        const SpreadsheetCellCoordinates AL(38,rowIndex);
        EXPECT_EQ(AL.getColumnIndexAsString(),std::string("AL"));

        const SpreadsheetCellCoordinates AM(39,rowIndex);
        EXPECT_EQ(AM.getColumnIndexAsString(),std::string("AM"));

        const SpreadsheetCellCoordinates AN(40,rowIndex);
        EXPECT_EQ(AN.getColumnIndexAsString(),std::string("AN"));

        const SpreadsheetCellCoordinates AO(41,rowIndex);
        EXPECT_EQ(AO.getColumnIndexAsString(),std::string("AO"));

        const SpreadsheetCellCoordinates AP(42,rowIndex);
        EXPECT_EQ(AP.getColumnIndexAsString(),std::string("AP"));

        const SpreadsheetCellCoordinates AQ(43,rowIndex);
        EXPECT_EQ(AQ.getColumnIndexAsString(),std::string("AQ"));

        const SpreadsheetCellCoordinates AR(44,rowIndex);
        EXPECT_EQ(AR.getColumnIndexAsString(),std::string("AR"));

        const SpreadsheetCellCoordinates AS(45,rowIndex);
        EXPECT_EQ(AS.getColumnIndexAsString(),std::string("AS"));

        const SpreadsheetCellCoordinates AT(46,rowIndex);
        EXPECT_EQ(AT.getColumnIndexAsString(),std::string("AT"));

        const SpreadsheetCellCoordinates AU(47,rowIndex);
        EXPECT_EQ(AU.getColumnIndexAsString(),std::string("AU"));

        const SpreadsheetCellCoordinates AV(48,rowIndex);
        EXPECT_EQ(AV.getColumnIndexAsString(),std::string("AV"));

        const SpreadsheetCellCoordinates AW(49,rowIndex);
        EXPECT_EQ(AW.getColumnIndexAsString(),std::string("AW"));

        const SpreadsheetCellCoordinates AX(50,rowIndex);
        EXPECT_EQ(AX.getColumnIndexAsString(),std::string("AX"));

        const SpreadsheetCellCoordinates AY(51,rowIndex);
        EXPECT_EQ(AY.getColumnIndexAsString(),std::string("AY"));

        const SpreadsheetCellCoordinates AZ(52,rowIndex);
        EXPECT_EQ(AZ.getColumnIndexAsString(),std::string("AZ"));

        const SpreadsheetCellCoordinates BA(53,rowIndex);
        EXPECT_EQ(BA.getColumnIndexAsString(),std::string("BA"));
    }
}