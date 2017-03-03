/*
 *
 * Author: Qiang Li
 * Email : liqiangneu@gmail.com
 * Date  : 11/14/2016
 * Time  : 14:24
 *
 */

#ifndef POSTPROCESS_UNKS_
#define POSTPROCESS_UNKS_

#include <unordered_map>
#include <string>
#include <fstream>
#include <iostream>
#include <map>

#include "utility_cu.h"
#include "utility_cc.h"

namespace neural_machine_translation {

class PostProcessUnks {

public:
  std::unordered_map<std::string, std::string> uno_dict_;
  std::unordered_map<std::string, bool> uno_stopwords_;
  std::unordered_map<std::string, bool> uno_end_punctuations_;

public:
  BasicMethod basic_method_;

public:
  PostProcessUnks() {};
  ~PostProcessUnks() {};

public:
  void LoadDicrionary(std::string &unk_dict_file_name);
  void LoadStopwords(std::string &unk_stopword_file_name);
  void LoadEndPunctuation(std::string &unk_stopword_file_name);
  void Processing(std::string &line_source, std::string &line_nmt_translation, std::string &line_output, bool &output_oov_mode);

public:
  /*
  void FindNumber(std::unordered_map<int, std::string> &uno_generalization_number, std::string &align_scores, \
                  std::vector<std::string> &v_source_words, int &position);
  void FindTime(std::unordered_map<int, std::string> &uno_generalization_time, std::string &align_scores, \
                std::vector<std::string> &v_source_words, int &position);
  void FindDate(std::unordered_map<int, std::string> &uno_generalization_date, std::string &align_scores, \
                std::vector<std::string> &v_source_words, int &position);
  void FindPerson(std::unordered_map<int, std::string> &uno_generalization_person, std::string &align_scores, \
                  std::vector<std::string> &v_source_words, int &position);
  */

  void TargetIsGeneralization(std::unordered_map<int, std::string> &uno_generalization, std::vector<std::string> &v_source_words, \
                              std::vector<int> &v_target_align, \
                              std::vector<std::string> &v_target_align_scores, int &i, bool &output_oov_mode, std::string label, std::string &line_output);

  void FindGeneralization(std::unordered_map<int, std::string> &uno_generalization, std::string &align_scores, \
                          std::vector<std::string> &v_source_words, int &position);

  void FindUnStopword(std::string &align_scores, std::vector<std::string> &v_source_words, int &position);

};

} // end of neural_machine_translation namespace


#endif

