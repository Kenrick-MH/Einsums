/*
  Copyright 2018 Paul Springer
  
  Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
  
  1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
  
  2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
  
  3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
  
  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include <memory>
#include <vector>

#include <Einsums/HPTT/Transpose.hpp>

namespace hptt {

std::shared_ptr<hptt::Transpose<float>>
create_plan(const int *perm, const int dim, const float alpha, const float *A,
            const int *sizeA, const int *outerSizeA, const float beta, float *B,
            const int *outerSizeB, const SelectionMethod selectionMethod,
            const int numThreads, const int *threadIds,
            const bool useRowMajor) {
  auto plan(std::make_shared<hptt::Transpose<float>>(
      sizeA, perm, outerSizeA, outerSizeB, nullptr, nullptr, 1, 1, 
      dim, A, alpha, B, beta, selectionMethod, numThreads, threadIds, useRowMajor));
  return plan;
}

std::shared_ptr<hptt::Transpose<double>>
create_plan(const int *perm, const int dim, const double alpha, const double *A,
            const int *sizeA, const int *outerSizeA, const double beta,
            double *B, const int *outerSizeB,
            const SelectionMethod selectionMethod, const int numThreads,
            const int *threadIds, const bool useRowMajor) {
  auto plan(std::make_shared<hptt::Transpose<double>>(
      sizeA, perm, outerSizeA, outerSizeB, nullptr, nullptr, 1, 1, 
      dim, A, alpha, B, beta, selectionMethod, numThreads, threadIds, useRowMajor));
  return plan;
}

std::shared_ptr<hptt::Transpose<FloatComplex>>
create_plan(const int *perm, const int dim, const FloatComplex alpha,
            const FloatComplex *A, const int *sizeA, const int *outerSizeA,
            const FloatComplex beta, FloatComplex *B, const int *outerSizeB,
            const SelectionMethod selectionMethod, const int numThreads,
            const int *threadIds, const bool useRowMajor) {
  auto plan(std::make_shared<hptt::Transpose<FloatComplex>>(
      sizeA, perm, outerSizeA, outerSizeB, nullptr, nullptr, 1, 1, 
      dim, A, alpha, B, beta, selectionMethod, numThreads, threadIds, useRowMajor));
  return plan;
}

std::shared_ptr<hptt::Transpose<DoubleComplex>>
create_plan(const int *perm, const int dim, const DoubleComplex alpha,
            const DoubleComplex *A, const int *sizeA, const int *outerSizeA,
            const DoubleComplex beta, DoubleComplex *B, const int *outerSizeB,
            const SelectionMethod selectionMethod, const int numThreads,
            const int *threadIds, const bool useRowMajor) {
  auto plan(std::make_shared<hptt::Transpose<DoubleComplex>>(
      sizeA, perm, outerSizeA, outerSizeB, nullptr, nullptr, 1, 1, 
      dim, A, alpha, B, beta, selectionMethod, numThreads, threadIds, useRowMajor));
  return plan;
}

std::shared_ptr<hptt::Transpose<float>>
create_plan(const std::vector<int> &perm, const int dim, const float alpha,
            const float *A, const std::vector<int> &sizeA,
            const std::vector<int> &outerSizeA, const float beta, float *B,
            const std::vector<int> &outerSizeB,
            const SelectionMethod selectionMethod, const int numThreads,
            const std::vector<int> &threadIds, const bool useRowMajor) {
  auto plan(std::make_shared<hptt::Transpose<float>>(
      &sizeA[0], &perm[0], &outerSizeA[0], &outerSizeB[0], nullptr, nullptr,
      1, 1, dim, A, alpha, B, beta, selectionMethod, numThreads,
      (threadIds.size() > 0) ? &threadIds[0] : nullptr, useRowMajor));
  return plan;
}

std::shared_ptr<hptt::Transpose<double>>
create_plan(const std::vector<int> &perm, const int dim, const double alpha,
            const double *A, const std::vector<int> &sizeA,
            const std::vector<int> &outerSizeA, const double beta, double *B,
            const std::vector<int> &outerSizeB,
            const SelectionMethod selectionMethod, const int numThreads,
            const std::vector<int> &threadIds, const bool useRowMajor) {
  auto plan(std::make_shared<hptt::Transpose<double>>(
      &sizeA[0], &perm[0], &outerSizeA[0], &outerSizeB[0], nullptr, nullptr,
      1, 1, dim, A, alpha, B, beta, selectionMethod, numThreads,
      (threadIds.size() > 0) ? &threadIds[0] : nullptr, useRowMajor));
  return plan;
}

std::shared_ptr<hptt::Transpose<FloatComplex>>
create_plan(const std::vector<int> &perm, const int dim,
            const FloatComplex alpha, const FloatComplex *A,
            const std::vector<int> &sizeA, const std::vector<int> &outerSizeA,
            const FloatComplex beta, FloatComplex *B,
            const std::vector<int> &outerSizeB,
            const SelectionMethod selectionMethod, const int numThreads,
            const std::vector<int> &threadIds, const bool useRowMajor) {
  auto plan(std::make_shared<hptt::Transpose<FloatComplex>>(
      &sizeA[0], &perm[0], &outerSizeA[0], &outerSizeB[0], nullptr, nullptr,
      1, 1, dim, A, alpha, B, beta, selectionMethod, numThreads,
      (threadIds.size() > 0) ? &threadIds[0] : nullptr, useRowMajor));
  return plan;
}

std::shared_ptr<hptt::Transpose<DoubleComplex>>
create_plan(const std::vector<int> &perm, const int dim,
            const DoubleComplex alpha, const DoubleComplex *A,
            const std::vector<int> &sizeA, const std::vector<int> &outerSizeA,
            const DoubleComplex beta, DoubleComplex *B,
            const std::vector<int> &outerSizeB,
            const SelectionMethod selectionMethod, const int numThreads,
            const std::vector<int> &threadIds, const bool useRowMajor) {
  auto plan(std::make_shared<hptt::Transpose<DoubleComplex>>(
      &sizeA[0], &perm[0], &outerSizeA[0], &outerSizeB[0], nullptr, nullptr,
      1, 1, dim, A, alpha, B, beta, selectionMethod, numThreads,
      (threadIds.size() > 0) ? &threadIds[0] : nullptr, useRowMajor));
  return plan;
}

std::shared_ptr<hptt::Transpose<float>>
create_plan(const int *perm, const int dim, const float alpha, const float *A,
            const int *sizeA, const int *outerSizeA, const float beta, float *B,
            const int *outerSizeB, const int maxAutotuningCandidates,
            const int numThreads, const int *threadIds,
            const bool useRowMajor) {
  auto plan(std::make_shared<hptt::Transpose<float>>(
      sizeA, perm, outerSizeA, outerSizeB, nullptr, nullptr, 1, 1,
      dim, A, alpha, B, beta, MEASURE, numThreads, threadIds, useRowMajor));
  plan->setMaxAutotuningCandidates(maxAutotuningCandidates);
  plan->createPlan();
  return plan;
}

std::shared_ptr<hptt::Transpose<double>>
create_plan(const int *perm, const int dim, const double alpha, const double *A,
            const int *sizeA, const int *outerSizeA, const double beta,
            double *B, const int *outerSizeB, const int maxAutotuningCandidates,
            const int numThreads, const int *threadIds,
            const bool useRowMajor) {
  auto plan(std::make_shared<hptt::Transpose<double>>(
      sizeA, perm, outerSizeA, outerSizeB, nullptr, nullptr, 1, 1,
      dim, A, alpha, B, beta, MEASURE, numThreads, threadIds, useRowMajor));
  plan->setMaxAutotuningCandidates(maxAutotuningCandidates);
  plan->createPlan();
  return plan;
}

std::shared_ptr<hptt::Transpose<FloatComplex>>
create_plan(const int *perm, const int dim, const FloatComplex alpha,
            const FloatComplex *A, const int *sizeA, const int *outerSizeA,
            const FloatComplex beta, FloatComplex *B, const int *outerSizeB,
            const int maxAutotuningCandidates, const int numThreads,
            const int *threadIds, const bool useRowMajor) {
  auto plan(std::make_shared<hptt::Transpose<FloatComplex>>(
      sizeA, perm, outerSizeA, outerSizeB, nullptr, nullptr, 1, 1,
      dim, A, alpha, B, beta, MEASURE, numThreads, threadIds, useRowMajor));
  plan->createPlan();
  return plan;
}

std::shared_ptr<hptt::Transpose<DoubleComplex>>
create_plan(const int *perm, const int dim, const DoubleComplex alpha,
            const DoubleComplex *A, const int *sizeA, const int *outerSizeA,
            const DoubleComplex beta, DoubleComplex *B, const int *outerSizeB,
            const int maxAutotuningCandidates, const int numThreads,
            const int *threadIds, const bool useRowMajor) {
  auto plan(std::make_shared<hptt::Transpose<DoubleComplex>>(
      sizeA, perm, outerSizeA, outerSizeB, nullptr, nullptr, 1, 1, 
      dim, A, alpha, B, beta, MEASURE, numThreads, threadIds, useRowMajor));
  plan->setMaxAutotuningCandidates(maxAutotuningCandidates);
  plan->createPlan();
  return plan;
}

/* Methods with (floats, doubles, FloatComplexes, and DoubleComplexes) (alpha, A, beta, and B), SelectionMethod Class, 
 * --int-- Offsets, and ints (sizeA, outerSizeA, and outerSizeB). */
std::shared_ptr<hptt::Transpose<float>> 
create_plan(const int *perm, const int dim, const float alpha, const float *A, const int *sizeA, 
            const int *outerSizeA, const int *offsetA, const float beta, float *B, 
            const int *outerSizeB, const int *offsetB, const SelectionMethod selectionMethod,
            const int numThreads, const int *threadIds, const bool useRowMajor)
{
   auto plan(std::make_shared<hptt::Transpose<float>>(
       sizeA, perm, outerSizeA, outerSizeB, offsetA, offsetB, 1, 1, dim, A, alpha, 
       B, beta, selectionMethod, numThreads, threadIds, useRowMajor));
   return plan;
}

std::shared_ptr<hptt::Transpose<double>> 
create_plan(const int *perm, const int dim, const double alpha, const double *A, const int *sizeA, 
            const int *outerSizeA, const int *offsetA, const double beta, double *B, 
            const int *outerSizeB, const int *offsetB, const SelectionMethod selectionMethod,
            const int numThreads, const int *threadIds, const bool useRowMajor)
{
   auto plan(std::make_shared<hptt::Transpose<double>>(
       sizeA, perm, outerSizeA, outerSizeB, offsetA, offsetB, 1, 1, dim, A, alpha, 
       B, beta, selectionMethod, numThreads, threadIds, useRowMajor));
   return plan;
}

std::shared_ptr<hptt::Transpose<FloatComplex>> 
create_plan(const int *perm, const int dim, const FloatComplex alpha, const FloatComplex *A, 
            const int *sizeA, const int *outerSizeA, const int *offsetA,
            const FloatComplex beta, FloatComplex *B, const int *outerSizeB, const int *offsetB,
            const SelectionMethod selectionMethod, const int numThreads, const int *threadIds, 
            const bool useRowMajor)
{
   auto plan(std::make_shared<hptt::Transpose<FloatComplex>>(
       sizeA, perm, outerSizeA, outerSizeB, offsetA, offsetB, 1, 1, dim, A, alpha, 
       B, beta, selectionMethod, numThreads, threadIds, useRowMajor));
   return plan;
}

std::shared_ptr<hptt::Transpose<DoubleComplex>> 
create_plan(const int *perm, const int dim, const DoubleComplex alpha, const DoubleComplex *A, 
            const int *sizeA, const int *outerSizeA, const int *offsetA, const DoubleComplex beta, 
            DoubleComplex *B, const int *outerSizeB, const int *offsetB, 
            const SelectionMethod selectionMethod, const int numThreads, const int *threadIds, 
            const bool useRowMajor)
{
   auto plan(std::make_shared<hptt::Transpose<DoubleComplex>>(
       sizeA, perm, outerSizeA, outerSizeB, offsetA, offsetB, 1, 1, dim, A, alpha, 
       B, beta, selectionMethod, numThreads, threadIds, useRowMajor));
   return plan;
}

/* Methods with (floats, doubles, FloatComplexes, and DoubleComplexes) (alpha, A, beta, and B), SelectionMethod Class, 
 * --vector int-- Offsets, and vector ints (sizeA, outerSizeA, and outerSizeB). */
std::shared_ptr<hptt::Transpose<float>> 
create_plan(const std::vector<int> &perm, const int dim, const float alpha, 
            const float *A, const std::vector<int> &sizeA, const std::vector<int> &outerSizeA, 
            const std::vector<int> &offsetA, const float beta, float *B, 
            const std::vector<int> &outerSizeB, const std::vector<int> &offsetB,
            const SelectionMethod selectionMethod,
            const int numThreads, const std::vector<int> &threadIds, const bool useRowMajor)
{
   auto plan(std::make_shared<hptt::Transpose<float>>(
       &sizeA[0], &perm[0], &outerSizeA[0], &outerSizeB[0], &offsetA[0], 
       &offsetB[0], 1, 1, dim, A, alpha, B, beta, selectionMethod, numThreads, 
       (threadIds.size() > 0 ) ? &threadIds[0] : nullptr, useRowMajor ));
   return plan;
}

std::shared_ptr<hptt::Transpose<double>> 
create_plan(const std::vector<int> &perm, const int dim, const double alpha, 
            const double *A, const std::vector<int> &sizeA, const std::vector<int> &outerSizeA, 
            const std::vector<int> &offsetA, const double beta, double *B, 
            const std::vector<int> &outerSizeB, const std::vector<int> &offsetB,
            const SelectionMethod selectionMethod,
            const int numThreads, const std::vector<int> &threadIds, const bool useRowMajor)
{
   auto plan(std::make_shared<hptt::Transpose<double>>(
       &sizeA[0], &perm[0], &outerSizeA[0], &outerSizeB[0], &offsetA[0], 
       &offsetB[0], 1, 1, dim, A, alpha, B, beta, selectionMethod, numThreads, 
       (threadIds.size() > 0 ) ? &threadIds[0] : nullptr, useRowMajor));
   return plan;
}

std::shared_ptr<hptt::Transpose<FloatComplex>> 
create_plan(const std::vector<int> &perm, const int dim, const FloatComplex alpha, 
            const FloatComplex *A, const std::vector<int> &sizeA, const std::vector<int> &outerSizeA, 
            const std::vector<int> &offsetA, const FloatComplex beta, FloatComplex *B, 
            const std::vector<int> &outerSizeB, const std::vector<int> &offsetB,
            const SelectionMethod selectionMethod, const int numThreads, 
            const std::vector<int> &threadIds, const bool useRowMajor)
{
   auto plan(std::make_shared<hptt::Transpose<FloatComplex>>(
       &sizeA[0], &perm[0], &outerSizeA[0], &outerSizeB[0], &offsetA[0], 
       &offsetB[0], 1, 1, dim, A, alpha, B, beta, selectionMethod, numThreads, 
       (threadIds.size() > 0 ) ? &threadIds[0] : nullptr, useRowMajor));
   return plan;
}

std::shared_ptr<hptt::Transpose<DoubleComplex>> 
create_plan(const std::vector<int> &perm, const int dim, const DoubleComplex alpha, 
            const DoubleComplex *A, const std::vector<int> &sizeA, const std::vector<int> &outerSizeA, 
            const std::vector<int> &offsetA, const DoubleComplex beta, DoubleComplex *B, 
            const std::vector<int> &outerSizeB, const std::vector<int> &offsetB,
            const SelectionMethod selectionMethod, const int numThreads, 
            const std::vector<int> &threadIds, const bool useRowMajor)
{
   auto plan(std::make_shared<hptt::Transpose<DoubleComplex>>(
       &sizeA[0], &perm[0], &outerSizeA[0], &outerSizeB[0], &offsetA[0], 
       &offsetB[0], 1, 1, dim, A, alpha, B, beta, selectionMethod, numThreads, 
       (threadIds.size() > 0 ) ? &threadIds[0] : nullptr, useRowMajor));
   return plan;
}

/* Methods with (floats, doubles, FloatComplexes, and DoubleComplexes) (alpha, A, beta, and B), --int-- maxAutotuningCandidates, 
 * --int-- Offsets, and ints (sizeA, outerSizeA, and outerSizeB). */
std::shared_ptr<hptt::Transpose<float>> 
create_plan(const int *perm, const int dim, const float alpha, 
            const float *A, const int *sizeA, const int *outerSizeA, const int *offsetA,
            const float beta, float *B, const int *outerSizeB, const int *offsetB,
            const int maxAutotuningCandidates, const int numThreads, const int *threadIds, 
            const bool useRowMajor)
{
   auto plan(std::make_shared<hptt::Transpose<float>>(
       sizeA, perm, outerSizeA, outerSizeB, offsetA, offsetB, 1, 1, dim, A, 
       alpha, B, beta, MEASURE, numThreads, threadIds, useRowMajor));
   plan->setMaxAutotuningCandidates(maxAutotuningCandidates);
   plan->createPlan();
   return plan;
}

std::shared_ptr<hptt::Transpose<double>> 
create_plan(const int *perm, const int dim, const double alpha, 
            const double *A, const int *sizeA, const int *outerSizeA, const int *offsetA,
            const double beta, double *B, const int *outerSizeB, const int *offsetB,
            const int maxAutotuningCandidates, const int numThreads, const int *threadIds, 
            const bool useRowMajor)
{
   auto plan(std::make_shared<hptt::Transpose<double>>(
       sizeA, perm, outerSizeA, outerSizeB, offsetA, offsetB, 1, 1, dim, A, 
       alpha, B, beta, MEASURE, numThreads, threadIds, useRowMajor));
   plan->setMaxAutotuningCandidates(maxAutotuningCandidates);
   plan->createPlan();
   return plan;
}

std::shared_ptr<hptt::Transpose<FloatComplex> > 
create_plan(const int *perm, const int dim, const FloatComplex alpha, 
            const FloatComplex *A, const int *sizeA, const int *outerSizeA, const int *offsetA,
            const FloatComplex beta, FloatComplex *B, const int *outerSizeB, const int *offsetB,
            const int maxAutotuningCandidates, const int numThreads, const int *threadIds, 
            const bool useRowMajor)
{
   auto plan(std::make_shared<hptt::Transpose<FloatComplex>>(
       sizeA, perm, outerSizeA, outerSizeB, offsetA, offsetB, 1, 1, dim, A, 
       alpha, B, beta, MEASURE, numThreads, threadIds, useRowMajor));
   plan->createPlan();
   return plan;
}

std::shared_ptr<hptt::Transpose<DoubleComplex>> 
create_plan(const int *perm, const int dim, const DoubleComplex alpha, 
            const DoubleComplex *A, const int *sizeA, const int *outerSizeA, const int *offsetA,
            const DoubleComplex beta, DoubleComplex *B, const int *outerSizeB, const int *offsetB,
            const int maxAutotuningCandidates, const int numThreads, const int *threadIds, 
            const bool useRowMajor)
{
   auto plan(std::make_shared<hptt::Transpose<DoubleComplex>>(
       sizeA, perm, outerSizeA, outerSizeB, offsetA, offsetB, 1, 1, dim, A, 
       alpha, B, beta, MEASURE, numThreads, threadIds, useRowMajor));
   plan->setMaxAutotuningCandidates(maxAutotuningCandidates);
   plan->createPlan();
   return plan;
}

/* Methods with (floats, doubles, FloatComplexes, and DoubleComplexes) (alpha, A, beta, and B), 
 * SelectionMethod Class, --int-- Offsets, --int-- innerStrides, and ints (sizeA, outerSizeA, and 
 * outerSizeB). */
std::shared_ptr<hptt::Transpose<float> > 
create_plan(const int *perm, const int dim, const float alpha, const float *A, const int *sizeA, 
            const int *outerSizeA, const int *offsetA, const int innerStrideA, const float beta, 
            float *B, const int *outerSizeB, const int *offsetB, const int innerStrideB,
            const SelectionMethod selectionMethod, const int numThreads, const int *threadIds, 
            const bool useRowMajor)
{
   auto plan(std::make_shared<hptt::Transpose<float> >(
        sizeA, perm, outerSizeA, outerSizeB, offsetA, offsetB, innerStrideA, innerStrideB, dim, 
        A, alpha, B, beta, selectionMethod, numThreads, threadIds, useRowMajor));
   return plan;
}

std::shared_ptr<hptt::Transpose<double> > 
create_plan(const int *perm, const int dim, const double alpha, const double *A, const int *sizeA, 
            const int *outerSizeA, const int *offsetA, const int innerStrideA, const double beta, 
            double *B, const int *outerSizeB, const int *offsetB, const int innerStrideB,
            const SelectionMethod selectionMethod, const int numThreads, const int *threadIds, 
            const bool useRowMajor)
{
   auto plan(std::make_shared<hptt::Transpose<double> >(
        sizeA, perm, outerSizeA, outerSizeB, offsetA, offsetB, innerStrideA, innerStrideB, dim, 
        A, alpha, B, beta, selectionMethod, numThreads, threadIds, useRowMajor));
   return plan;
}

std::shared_ptr<hptt::Transpose<FloatComplex> > 
create_plan(const int *perm, const int dim, const FloatComplex alpha, const FloatComplex *A, 
            const int *sizeA, const int *outerSizeA, const int *offsetA, const int innerStrideA,
            const FloatComplex beta, FloatComplex *B, const int *outerSizeB, const int *offsetB, 
            const int innerStrideB, const SelectionMethod selectionMethod, const int numThreads, 
            const int *threadIds, const bool useRowMajor)
{
   auto plan(std::make_shared<hptt::Transpose<FloatComplex> >(
        sizeA, perm, outerSizeA, outerSizeB, offsetA, offsetB, innerStrideA, innerStrideB, dim, 
        A, alpha, B, beta, selectionMethod, numThreads, threadIds, useRowMajor));
   return plan;
}

std::shared_ptr<hptt::Transpose<DoubleComplex> > 
create_plan(const int *perm, const int dim, const DoubleComplex alpha, const DoubleComplex *A, 
            const int *sizeA, const int *outerSizeA, const int *offsetA, const int innerStrideA,
            const DoubleComplex beta, DoubleComplex *B, const int *outerSizeB, const int *offsetB, 
            const int innerStrideB, const SelectionMethod selectionMethod, const int numThreads, 
            const int *threadIds, const bool useRowMajor)
{
   auto plan(std::make_shared<hptt::Transpose<DoubleComplex> >(
        sizeA, perm, outerSizeA, outerSizeB, offsetA, offsetB, innerStrideA, innerStrideB, dim, 
        A, alpha, B, beta, selectionMethod, numThreads, threadIds, useRowMajor));
   return plan;
}

/* Methods with (floats, doubles, FloatComplexes, and DoubleComplexes) (alpha, A, beta, and B), SelectionMethod Class, 
 * --vector int-- Offsets, --int-- innerStrides, and vector ints (sizeA, outerSizeA, and outerSizeB). */
std::shared_ptr<hptt::Transpose<float> > 
create_plan(const std::vector<int> &perm, const int dim, const float alpha, const float *A, 
            const std::vector<int> &sizeA, const std::vector<int> &outerSizeA, 
            const std::vector<int> &offsetA, const int innerStrideA,const float beta, float *B, 
            const std::vector<int> &outerSizeB, const std::vector<int> &offsetB, 
            const int innerStrideB, const SelectionMethod selectionMethod, const int numThreads, 
            const std::vector<int> &threadIds, const bool useRowMajor)
{
   auto plan(std::make_shared<hptt::Transpose<float> >(
        &sizeA[0], &perm[0], &outerSizeA[0], &outerSizeB[0], &offsetA[0], &offsetB[0], 
        innerStrideA, innerStrideB, dim, A, alpha, B, beta, selectionMethod, numThreads, 
        (threadIds.size() > 0 ) ? &threadIds[0] : nullptr, useRowMajor));
   return plan;
}

std::shared_ptr<hptt::Transpose<double> > 
create_plan(const std::vector<int> &perm, const int dim, const double alpha, const double *A, 
            const std::vector<int> &sizeA, const std::vector<int> &outerSizeA, 
            const std::vector<int> &offsetA, const int innerStrideA, const double beta, 
            double *B, const std::vector<int> &outerSizeB, const std::vector<int> &offsetB, 
            const int innerStrideB, const SelectionMethod selectionMethod, const int numThreads, 
            const std::vector<int> &threadIds, const bool useRowMajor)
{
   auto plan(std::make_shared<hptt::Transpose<double> >(
        &sizeA[0], &perm[0], &outerSizeA[0], &outerSizeB[0], &offsetA[0], &offsetB[0], 
        innerStrideA, innerStrideB, dim, A, alpha, B, beta, selectionMethod, numThreads, 
        (threadIds.size() > 0 ) ? &threadIds[0] : nullptr, useRowMajor));
   return plan;
}

std::shared_ptr<hptt::Transpose<FloatComplex> > 
create_plan(const std::vector<int> &perm, const int dim, const FloatComplex alpha, 
            const FloatComplex *A, const std::vector<int> &sizeA, 
            const std::vector<int> &outerSizeA, const std::vector<int> &offsetA, 
            const int innerStrideA, const FloatComplex beta, FloatComplex *B, 
            const std::vector<int> &outerSizeB, const std::vector<int> &offsetB, 
            const int innerStrideB, const SelectionMethod selectionMethod, const int numThreads, 
            const std::vector<int> &threadIds, const bool useRowMajor)
{
   auto plan(std::make_shared<hptt::Transpose<FloatComplex> >(
        &sizeA[0], &perm[0], &outerSizeA[0], &outerSizeB[0], &offsetA[0], &offsetB[0], 
        innerStrideA, innerStrideB, dim, A, alpha, B, beta, selectionMethod, numThreads, 
        (threadIds.size() > 0 ) ? &threadIds[0] : nullptr, useRowMajor ));
   return plan;
}

std::shared_ptr<hptt::Transpose<DoubleComplex> > 
create_plan(const std::vector<int> &perm, const int dim, const DoubleComplex alpha, 
            const DoubleComplex *A, const std::vector<int> &sizeA, 
            const std::vector<int> &outerSizeA, const std::vector<int> &offsetA, 
            const int innerStrideA, const DoubleComplex beta, DoubleComplex *B, 
            const std::vector<int> &outerSizeB, const std::vector<int> &offsetB, 
            const int innerStrideB, const SelectionMethod selectionMethod, const int numThreads, 
            const std::vector<int> &threadIds, const bool useRowMajor)
{
   auto plan(std::make_shared<hptt::Transpose<DoubleComplex> >(
        &sizeA[0], &perm[0], &outerSizeA[0], &outerSizeB[0], &offsetA[0], &offsetB[0], 
        innerStrideA, innerStrideB, dim, A, alpha, B, beta, selectionMethod, numThreads, 
        (threadIds.size() > 0 ) ? &threadIds[0] : nullptr, useRowMajor ));
   return plan;
}

/* Methods with (floats, doubles, FloatComplexes, and DoubleComplexes) (alpha, A, beta, and B), --int-- maxAutotuningCandidates, 
 * --int-- Offsets, --int-- innerStrides, and ints (sizeA, outerSizeA, and outerSizeB). */
std::shared_ptr<hptt::Transpose<float> > 
create_plan(const int *perm, const int dim, const float alpha, const float *A, const int *sizeA, 
            const int *outerSizeA, const int *offsetA, const int innerStrideA, const float beta, 
            float *B, const int *outerSizeB, const int *offsetB, const int innerStrideB,
            const int maxAutotuningCandidates, const int numThreads, const int *threadIds, 
            const bool useRowMajor)
{
   auto plan(std::make_shared<hptt::Transpose<float> >(
        sizeA, perm, outerSizeA, outerSizeB, offsetA, offsetB, innerStrideA, innerStrideB, dim, 
        A, alpha, B, beta, MEASURE, numThreads, threadIds, useRowMajor));
   plan->setMaxAutotuningCandidates(maxAutotuningCandidates);
   plan->createPlan();
   return plan;
}

std::shared_ptr<hptt::Transpose<double> > 
create_plan(const int *perm, const int dim, const double alpha, const double *A, const int *sizeA, 
            const int *outerSizeA, const int *offsetA, const int innerStrideA, const double beta, 
            double *B, const int *outerSizeB, const int *offsetB, const int innerStrideB,
            const int maxAutotuningCandidates, const int numThreads, const int *threadIds, 
            const bool useRowMajor)
{
   auto plan(std::make_shared<hptt::Transpose<double> >(
        sizeA, perm, outerSizeA, outerSizeB, offsetA, offsetB, innerStrideA, innerStrideB, dim, 
        A, alpha, B, beta, MEASURE, numThreads, threadIds, useRowMajor));
   plan->setMaxAutotuningCandidates(maxAutotuningCandidates);
   plan->createPlan();
   return plan;
}

std::shared_ptr<hptt::Transpose<FloatComplex> > 
create_plan(const int *perm, const int dim, const FloatComplex alpha, const FloatComplex *A, 
            const int *sizeA, const int *outerSizeA, const int *offsetA, const int innerStrideA,
            const FloatComplex beta, FloatComplex *B, const int *outerSizeB, const int *offsetB, 
            const int innerStrideB, const int maxAutotuningCandidates, const int numThreads, 
            const int *threadIds, const bool useRowMajor)
{
   auto plan(std::make_shared<hptt::Transpose<FloatComplex> >(
        sizeA, perm, outerSizeA, outerSizeB, offsetA, offsetB, innerStrideA, innerStrideB, dim, 
        A, alpha, B, beta, MEASURE, numThreads, threadIds, useRowMajor));
   plan->createPlan();
   return plan;
}

std::shared_ptr<hptt::Transpose<DoubleComplex> > 
create_plan(const int *perm, const int dim, const DoubleComplex alpha, const DoubleComplex *A, 
            const int *sizeA, const int *outerSizeA, const int *offsetA, const int innerStrideA,
            const DoubleComplex beta, DoubleComplex *B, const int *outerSizeB, const int *offsetB, 
            const int innerStrideB, const int maxAutotuningCandidates, const int numThreads, 
            const int *threadIds, const bool useRowMajor)
{
   auto plan(std::make_shared<hptt::Transpose<DoubleComplex> >(
        sizeA, perm, outerSizeA, outerSizeB, offsetA, offsetB, innerStrideA, innerStrideB, dim, 
        A, alpha, B, beta, MEASURE, numThreads, threadIds, useRowMajor ));
   plan->setMaxAutotuningCandidates(maxAutotuningCandidates);
   plan->createPlan();
   return plan;
}
} // namespace hptt

#if 0
extern "C" {
void sTensorTranspose(const int *perm, const int dim, const float alpha,
                      const float *A, const int *sizeA, const int *outerSizeA,
                      const float beta, float *B, const int *outerSizeB,
                      const int numThreads, const int useRowMajor) {
  auto plan(std::make_shared<hptt::Transpose<float>>(
      sizeA, perm, outerSizeA, outerSizeB, nullptr, nullptr, 1, 1,
      dim, A, alpha, B, beta, hptt::ESTIMATE, numThreads, nullptr, useRowMajor));
  plan->execute();
}

void dTensorTranspose(const int *perm, const int dim, const double alpha,
                      const double *A, const int *sizeA, const int *outerSizeA,
                      const double beta, double *B, const int *outerSizeB,
                      const int numThreads, const int useRowMajor) {
  auto plan(std::make_shared<hptt::Transpose<double>>(
      sizeA, perm, outerSizeA, outerSizeB, nullptr, nullptr, 1, 1,
      dim, A, alpha, B, beta, hptt::ESTIMATE, numThreads, nullptr, useRowMajor));
  plan->execute();
}

void cTensorTranspose(const int *perm, const int dim,
                      const float _Complex alpha, bool conjA,
                      const float _Complex *A, const int *sizeA,
                      const int *outerSizeA, const float _Complex beta,
                      float _Complex *B, const int *outerSizeB,
                      const int numThreads, const int useRowMajor) {
  auto plan(std::make_shared<hptt::Transpose<hptt::FloatComplex>>(
      sizeA, perm, outerSizeA, outerSizeB, nullptr, nullptr, 1, 1,
      dim, (const hptt::FloatComplex *)A, (hptt::FloatComplex)alpha, 
      (hptt::FloatComplex *)B, (hptt::FloatComplex)beta, hptt::ESTIMATE, 
      numThreads, nullptr, useRowMajor));
  plan->setConjA(conjA);
  plan->execute();
}

void zTensorTranspose(const int *perm, const int dim,
                      const double _Complex alpha, bool conjA,
                      const double _Complex *A, const int *sizeA,
                      const int *outerSizeA, const double _Complex beta,
                      double _Complex *B, const int *outerSizeB,
                      const int numThreads, const int useRowMajor) {
  auto plan(std::make_shared<hptt::Transpose<hptt::DoubleComplex>>(
      sizeA, perm, outerSizeA, outerSizeB, nullptr, nullptr, 1, 1,
      dim, (const hptt::DoubleComplex *)A, (hptt::DoubleComplex)alpha, 
      (hptt::DoubleComplex *)B, (hptt::DoubleComplex)beta, hptt::ESTIMATE, 
      numThreads, nullptr, useRowMajor));
  plan->setConjA(conjA);
  plan->execute();
}

/* With Offset */
void sOffsetTensorTranspose(const int *perm, const int dim, const float alpha, 
                            const float *A, const int *sizeA, const int *outerSizeA, const int *offsetA,
                            const float beta, float *B, const int *outerSizeB, const int *offsetB,
                            const int numThreads, const int useRowMajor)
{
  auto plan(std::make_shared<hptt::Transpose<float> >(
      sizeA, perm, outerSizeA, outerSizeB, offsetA, offsetB, 1, 1 dim, A, alpha, 
      B, beta, hptt::ESTIMATE, numThreads, nullptr, useRowMajor));
  plan->execute();
}

void dOffsetTensorTranspose(const int *perm, const int dim, const double alpha, 
                            const double *A, const int *sizeA, const int *outerSizeA, const int *offsetA, 
                            const double beta, double *B, const int *outerSizeB, const int *offsetB,
                            const int numThreads, const int useRowMajor)
{
  auto plan(std::make_shared<hptt::Transpose<double> >(
      sizeA, perm, outerSizeA, outerSizeB, offsetA, offsetB, 1, 1 dim, A, alpha, 
      B, beta, hptt::ESTIMATE, numThreads, nullptr, useRowMajor));
  plan->execute();
}

void cOffsetTensorTranspose(const int *perm, const int dim,
                            const float _Complex alpha, bool conjA, 
                            const float _Complex *A, const int *sizeA, const int *outerSizeA, const int *offsetA, 
                            const float _Complex beta, float _Complex *B, const int *outerSizeB, const int *offsetB,
                            const int numThreads, const int useRowMajor)
{
  auto plan(std::make_shared<hptt::Transpose<hptt::FloatComplex> >(
      sizeA, perm, outerSizeA, outerSizeB, offsetA, offsetB, 1, 1 dim, 
      (const hptt::FloatComplex*) A, (hptt::FloatComplex)(__real__ alpha, __imag__ alpha), 
      (hptt::FloatComplex*) B, (hptt::FloatComplex)(__real__ beta, __imag__ beta), 
      hptt::ESTIMATE, numThreads, nullptr, useRowMajor));
  plan->setConjA(conjA);
  plan->execute();
}

void zOffsetTensorTranspose(const int *perm, const int dim,
                            const double _Complex alpha, bool conjA, 
                            const double _Complex *A, const int *sizeA, const int *outerSizeA, const int *offsetA, 
                            const double _Complex beta, double _Complex *B, const int *outerSizeB, const int *offsetB,
                            const int numThreads, const int useRowMajor)
{
  auto plan(std::make_shared<hptt::Transpose<hptt::DoubleComplex> >(
      sizeA, perm, outerSizeA, outerSizeB, offsetA, offsetB, 1, 1 dim, 
      (const hptt::DoubleComplex*) A, (hptt::DoubleComplex)(__real__ alpha, __imag__ alpha), 
      (hptt::DoubleComplex*) B, (hptt::DoubleComplex)(__real__ beta, __imag__ beta), 
      hptt::ESTIMATE, numThreads, nullptr, useRowMajor));
  plan->setConjA(conjA);
  plan->execute();
}

/* With Offset and innerStride */
void sInnerStrideTensorTranspose(const int *perm, const int dim, const float alpha, 
                                 const float *A, const int *sizeA, const int *outerSizeA, 
                                 const int *offsetA, const int innerStrideA, const float beta,
                                 float *B, const int *outerSizeB, const int *offsetB, 
                                 const int innerStrideB, const int numThreads, 
                                 const int useRowMajor)
{
   auto plan(std::make_shared<hptt::Transpose<float> >(
        sizeA, perm, outerSizeA, outerSizeB, offsetA, offsetB, innerStrideA, innerStrideB, dim,
        A, alpha, B, beta, hptt::ESTIMATE, numThreads, nullptr, useRowMajor));
   plan->execute();
}

void dInnerStrideTensorTranspose(const int *perm, const int dim, const double alpha, 
                                 const double *A, const int *sizeA, const int *outerSizeA, 
                                 const int *offsetA, const int innerStrideA, const double beta,
                                 double *B, const int *outerSizeB, const int *offsetB, 
                                 const int innerStrideB, const int numThreads, 
                                 const int useRowMajor)
{
   auto plan(std::make_shared<hptt::Transpose<double> >(
        sizeA, perm, outerSizeA, outerSizeB, offsetA, offsetB, innerStrideA, innerStrideB, dim, 
        A, alpha, B, beta, hptt::ESTIMATE, numThreads, nullptr, useRowMajor));
   plan->execute();
}

void cInnerStrideTensorTranspose(const int *perm, const int dim, const float _Complex alpha, 
                                 bool conjA, const float _Complex *A, const int *sizeA, 
                                 const int *outerSizeA, const int *offsetA, const int innerStrideA, 
                                 const float _Complex beta, float _Complex *B, const int *outerSizeB, 
                                 const int *offsetB, const int innerStrideB, const int numThreads, 
                                 const int useRowMajor)
{
   auto plan(std::make_shared<hptt::Transpose<hptt::FloatComplex> >(
        sizeA, perm, outerSizeA, outerSizeB, offsetA, offsetB, innerStrideA, innerStrideB, dim, 
        (const hptt::FloatComplex*) A, (hptt::FloatComplex)(__real__ alpha, __imag__ alpha), 
        (hptt::FloatComplex*) B, (hptt::FloatComplex)(__real__ beta, __imag__ beta), hptt::ESTIMATE, 
        numThreads, nullptr, useRowMajor));
   plan->setConjA(conjA);
   plan->execute();
}

void zInnerStrideTensorTranspose(const int *perm, const int dim, const double _Complex alpha, 
                                 bool conjA, const double _Complex *A, const int *sizeA, 
                                 const int *outerSizeA, const int *offsetA, const int innerStrideA, 
                                 const double _Complex beta, double _Complex *B, const int *outerSizeB, 
                                 const int *offsetB, const int innerStrideB, const int numThreads, 
                                 const int useRowMajor)
{
   auto plan(std::make_shared<hptt::Transpose<hptt::DoubleComplex> >(
        sizeA, perm, outerSizeA, outerSizeB, offsetA, offsetB, innerStrideA, innerStrideB, dim, 
        (const hptt::DoubleComplex*) A, (hptt::DoubleComplex)(__real__ alpha, __imag__ alpha), 
        (hptt::DoubleComplex*) B, (hptt::DoubleComplex)(__real__ beta, __imag__ beta), hptt::ESTIMATE, 
        numThreads, nullptr, useRowMajor));
   plan->setConjA(conjA);
   plan->execute();
}
}
#endif