



#ifndef __OPERATION_RULE_EXECUTION_OBJECT_HPP__
#define __OPERATION_RULE_EXECUTION_OBJECT_HPP__

// =-=-=-=-=-=-=-
// irods includes
#include "rcConnect.hpp"

// =-=-=-=-=-=-=-
#include "irods_operation_rule_execution_manager_base.hpp"

// =-=-=-=-=-=-=-
// stl includes
#include <string>

namespace irods {

// =-=-=-=-=-=-=-
    /**
      * \class  operation_rule_execution_manager
      * \author Jason M. Coposky
      * \date   January 2013
      * \brief  class which builds operation rule names, queries for the rule existence,
      *         and provides an interface for execution in a pre and post operation condition
      **/
    class operation_rule_execution_manager : public
            operation_rule_execution_manager_base {
    public:
        /// =-=-=-=-=-=-=-
        /// @brief Constructor
        operation_rule_execution_manager(
            const std::string&,   // name of the plugin
            const std::string& ); // operation name

        /// =-=-=-=-=-=-=-
        /// @brief necessary virtual dtor
        virtual ~operation_rule_execution_manager() {}

        /// =-=-=-=-=-=-=-
        /// @brief execute rule for pre operation
        virtual error exec_pre_op(
            keyValPair_t&,      // vars from fco
            std::string& ); // results of call to rule

        /// =-=-=-=-=-=-=-
        /// @brief execute rule for post operation
        virtual error exec_post_op(
            keyValPair_t&,      // vars from fco
            std::string& ); // results of call to rule

    protected:

        /// =-=-=-=-=-=-=-
        /// @brief name of the rule minus the _pre or _post
        std::string rule_name_;

        /// =-=-=-=-=-=-=-
        /// @brief execute rule for post operation
        virtual error exec_op(
            keyValPair_t&,      // vars from fco
            const std::string&, // rule name
            std::string& );     // results of call to rule

    }; // class operation_rule_execution_manager

}; // namespace irods


#endif // __OPERATION_RULE_EXECUTION_OBJECT_HPP__



