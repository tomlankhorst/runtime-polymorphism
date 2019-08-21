#pragma once

#include <ostream>
#include <memory>

#include "Drawing.hpp"

/**
 * A drawable, drawable make up documents a
 */
class object_t {

  /**
   * Internal concept interface
   */
  struct concept_t {
    virtual ~concept_t() = default;
    virtual void draw_(std::ostream&, size_t) const = 0;
  };

  /**
   * Data model for a drawable
   * @tparam DrawableData
   */
  template <typename DrawableData>
  struct model final : concept_t {
    explicit model(DrawableData x) : data_(std::move(x)) {}
    void draw_(std::ostream& out, size_t position) const override
    { draw(data_, out, position); }
    DrawableData data_;
  };

public:

  template <typename DrawableData>
  explicit object_t(DrawableData x) : self_(std::make_shared<model<DrawableData>>(std::move(x)))
  {}

  friend void draw(const object_t& x, std::ostream& out, size_t position)
  { x.self_->draw_(out, position); }

private:
  std::shared_ptr<const concept_t> self_;
};

