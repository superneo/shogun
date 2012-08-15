/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * Written (W) 2012 Viktor Gal
 * Copyright (C) 2012 Viktor Gal
 */

#ifndef __LATENTSOSVM_H__
#define __LATENTSOSVM_H__

#include <shogun/machine/LinearLatentMachine.h>
#include <shogun/machine/LinearStructuredOutputMachine.h>

namespace shogun
{
	/**
	 * @brief TODO
	 *
	 */
	class CLatentSOSVM: public CLinearLatentMachine
	{
		public:
			/** default ctor*/
			CLatentSOSVM();

			/**
			 *
			 * @param model
			 * @param so_solver
			 * @param C
			 */
			CLatentSOSVM(CLatentModel* model, CLinearStructuredOutputMachine* so_solver, float64_t C);

			virtual ~CLatentSOSVM();

			/** apply linear machine to data
			 *
			 * @param data (test)data to be classified
			 * @return classified labels
			 */
			virtual CLatentLabels* apply();

			void set_so_solver(CLinearStructuredOutputMachine* so);

			/** Returns the name of the SGSerializable instance.
			 *
			 * @return name of the SGSerializable
			 */
			virtual const char* get_name() const { return "LatentSOSVM"; }

		protected:
			virtual float64_t do_inner_loop(float64_t cooling_eps);

		private:
			void register_parameters();

		private:
			/** Linear Structured Solver */
			CLinearStructuredOutputMachine* m_so_solver;
	};
}

#endif /* __LATENTSOSVM_H__ */

