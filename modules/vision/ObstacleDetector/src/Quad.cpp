/*
 * This file is part of FeatureDetector.
 *
 * FeatureDetector is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * FeatureDetector is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with FeatureDetector.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Copyright 2013 NUBots <nubots@nubots.net>
 */

#include "Quad.h"

namespace modules {
	namespace vision {	

		Quad::Quad() : bl(arma::zeros<arma::vec>(2)), br(arma::zeros<arma::vec>(2)), tr(arma::zeros<arma::vec>(2)), tl(arma::zeros<arma::vec>(2)) {
		}

		Quad::Quad(const Quad& other) {
			set(other.bl, other.tl, other.tr, other.br);
		}

		Quad::Quad(const arma::vec2& bottomLeft, const arma::vec2& topLeft, const arma::vec2& topRight, const arma::vec2& bottomRight) {
			set(bottom_left, top_left, top_right, bottom_right);
		}

		Quad::Quad(int left, int top, int right, int bottom) {
			set(left, top, right, bottom);
		}

		void Quad::set(int left, int top, int right, int bottom) {
			bl[0] = left;			bl[1] = bottom;
			br[0] = right;			br[1] = bottom;
			tl[0] = left;			tl[1] = top;
			tr[0] = right;			tr[1] = top;
		}

		void Quad::set(const arma::vec2& bottomLeft, const arma::vec2& topLeft, const arma::vec2& topRight, const arma::vec2& bottomRight) {
			bl = bottomLeft;
			tl = topLeft;
			tr = topRight;
			br = bottomRight;
		}

		arma::vec2 Quad::getCentre() const {
			return ((bl + tl + tr + br) * 0.25);
		}

		double Quad::getAverageWidth() const {
			return ((0.5 * (arma::norm(br - bl, 2) + arma::norm(tr - tl, 2))) + 1);
		}

		double Quad::getAverageHeight() const {
			return ((0.5 * (arma::norm(br - tr, 2) + arma::norm(bl - tl, 2))) + 1);
		}

		double Quad::area() const {
			// Area of a quadrilateral: A = 0.5 * |diag1 X diag2|
			// In two dimensions, this equates to: A = 0.5 * |(diag1.x)(diag2.y) - (diag2.x)(diag2.y)|
			
			arma::vec2 diag1 = bl - tr;
			arma::vec2 diag2 = tl - br;
			double signedArea = 0.5 * (diag1[0]diag2[1] - diag1[1]diag2[0]);
			
			return ((signedArea < 0) ? -signedArea : signedArea);
		}

		double Quad::aspectRatio() const {
			return ((arma::norm(br - tr, 2) + arma::norm(bl - tl, 2) + 2) / (arma::norm(br - bl, 2) + arma::norm(tr - tl, 2) + 2));
		}

		bool Quad::overlapsHorizontally(const Quad &other) const {
			// Rough for now.
			double farRight = std::max(tr[0], br[0]);
			double farLeft = std::min(tl[0], bl[0]);
			double o_farRight = std::max(other.tr[0], other.br[0]);
			double o_farLeft = std::min(other.tl[0], other.bl[0]);

			return !((farRight < o_farLeft) || (o_farRight < farLeft));
		}

		arma::vec2 getTopCentre() const {
			return ((tl + tr, 2) * 0.5);
		}
		
		arma::vec2 getBottomCentre() const {
			return ((bl + br) * 0.5);
		}

		arma::vec2 getBottomLeft() const {
			return bl;
		}
		
		arma::vec2 getBottomRight() const {
			return br;
		}
		
		arma::vec2 getTopLeft() const {
			return tl;
		}
		
		arma::vec2 getTopRight() const {
			return tr;
		}

		double getLeft() const {
			return (0.5 * (bl.x + tl.x));
		}
		
		double getRight() const {
			return (0.5 * (br.x + tr.x));
		}
		
		double getTop() const {
			return (0.5 * (tl.y + tr.y));
		}
		
		double getBottom() const {
			return (0.5 * (bl.y + br.y));
		}

		/// @brief Stream insertion operator for a single Quad.
		/// @relates Quad
		std::ostream& operator<< (std::ostream& output, const Quad& q) {
			output << "(" << q.bl[0] << ", " << q.bl[1] << ") (" << q.tl[0] << ", " << q.tl[1] << ") (" << q.tr[0] << ", " << q.tr[1] << ") (" << q.br[0] << ", " << q.br[1] << ")";
			return output;
		}

		/// @brief Stream insertion operator for a std::vector of Quads.
		///  @relates Quad
		std::ostream& operator<< (std::ostream& output, const std::vector<Quad>& q) {
			output << "[";
			
			for (const auto& it : q)
				output << it << ", ";
				
			output << "]";
			
			return output;
		}
	}
}

