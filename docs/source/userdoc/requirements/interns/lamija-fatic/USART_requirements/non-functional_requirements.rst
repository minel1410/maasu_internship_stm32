Non-functional Requirements
==========================

.. req:: System Performance
   :id: REQ_INT3_17310281820876
   :status: Draft
   :date-released: 2024-12-02
   :priority: High
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Non-Functional
   :safety-asil:
   :references:
   :verification-and-validation:

   The system must process user requests and transmit data through USART within 50 milliseconds.

.. req:: Scalability
   :id: REQ_INT3_17310281820877
   :status: Draft
   :date-released: 2024-12-02
   :priority: Medium
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Non-Functional
   :safety-asil:
   :references:
   :verification-and-validation:

   The system must be scalable to handle an increase in users, devices, or communication channels without a decrease in performance.

.. req:: Reliability
   :id: REQ_INT3_17310281820878
   :status: Draft
   :date-released: 2024-12-02
   :priority: High
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Non-Functional
   :safety-asil:
   :references:
   :verification-and-validation:

   The system must ensure reliable USART communication with a data loss not exceeding 0.1%, ensuring data integrity and protection.

.. req:: Security
   :id: REQ_INT3_17310281820879
   :status: Draft
   :date-released: 2024-12-02
   :priority: High
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Non-Functional
   :safety-asil:
   :references:
   :verification-and-validation:

   The system must encrypt sensitive data transmitted over USART to prevent unauthorized interception and data breaches.

.. req:: Portability
   :id: REQ_INT3_17310281820882
   :status: Draft
   :date-released: 2024-12-02
   :priority: Medium
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Non-Functional
   :safety-asil:
   :references:
   :verification-and-validation:

   The system must be portable to different microcontroller models that support USART communication, supporting baud rates up to 115200 bps, with a maximum communication latency of 100ms.

.. req:: Compatibility
   :id: REQ_INT3_17310281820883
   :status: Draft
   :date-released: 2024-12-02
   :priority: Medium
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Non-Functional
   :safety-asil:
   :references:
   :verification-and-validation:

   The system must ensure compatibility with external serial devices (e.g., sensors, actuators) that support standard USART communication protocols.

.. req:: Auditability
   :id: REQ_INT3_17310281820884
   :status: Draft
   :date-released: 2024-12-02
   :priority: Low
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Non-Functional
   :safety-asil:
   :references:
   :verification-and-validation:

   The system must maintain audit logs of USART communication events, including connection attempts, successful transfers, and error occurrences.

.. req:: Data Consistency
   :id: REQ_INT3_17310281820885
   :status: Draft
   :date-released: 2024-12-02
   :priority: High
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Non-Functional
   :safety-asil:
   :references:
   :verification-and-validation:

   The system must ensure data consistency during communication by verifying the integrity of each transmitted byte using checksums or parity bits.

.. req:: Timing Constraints
   :id: REQ_INT3_17310281820886
   :status: Draft
   :date-released: 2024-12-02
   :priority: High
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Non-Functional
   :safety-asil:
   :references:
   :verification-and-validation:

   The system must meet the timing constraints for USART data transmission and reception, ensuring each operation completes within 1 ms for byte transmission, 5 ms for data processing, 50 µs for interrupt response, and a timeout for inactivity after 100 ms.

.. req:: Real-time Communication
   :id: REQ_INT3_17310281820887
   :status: Draft
   :date-released: 2024-12-02
   :priority: High
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Non-Functional
   :safety-asil:
   :references:
   :verification-and-validation:

   The system must support real-time communication, enabling low-latency data exchange between devices without significant delays in USART operations.

.. req:: Availability
   :id: REQ_INT3_17310281820888
   :status: Draft
   :date-released: 2024-12-02
   :priority: High
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Non-Functional
   :safety-asil:
   :references:
   :verification-and-validation:

   The system must ensure high availability, with uptime of at least 99.7% for uninterrupted USART communication between devices.

.. req:: Error Handling
   :id: REQ_INT3_17310281820889
   :status: Draft
   :date-released: 2024-12-02
   :priority: High
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Non-Functional
   :safety-asil:
   :references:
   :verification-and-validation:

   The system must implement error detection and handling mechanisms to detect USART communication failures and trigger recovery actions.

.. req:: Power Consumption
   :id: REQ_INT3_17310281820890
   :status: Draft
   :date-released: 2024-12-02
   :priority: Medium
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Non-Functional
   :safety-asil:
   :references:
   :verification-and-validation:

   The system must optimize power consumption by using low-power modes during idle states of USART communication, minimizing the energy consumption of the microcontroller.

.. req:: Modularity
   :id: REQ_INT3_17310281820891
   :status: Draft
   :date-released: 2024-12-02
   :priority: Medium
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Non-Functional
   :safety-asil:
   :references:
   :verification-and-validation:

   The system must be modular to facilitate future upgrades, allowing easy integration of additional USART ports or other communication protocols.

.. req:: Configuration Flexibility
   :id: REQ_INT3_17310281820892
   :status: Draft
   :date-released: 2024-12-02
   :priority: Medium
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Non-Functional
   :safety-asil:
   :references:
   :verification-and-validation:

   The system must allow flexible configuration of USART parameters such as baud rate, oversampling, and data bits to adapt to different use cases and hardware setups.
.. req:: Software Updates
   :id: REQ_INT3_17310281820893
   :status: Draft
   :date-released: 2024-12-02
   :priority: Low
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Non-Functional
   :safety-asil:
   :references:
   :verification-and-validation:

   The system must support software updates, enabling the user to upgrade USART communication features and bug fixes without requiring hardware modifications.

.. req:: Fault Tolerance
   :id: REQ_INT3_17310281820894
   :status: Draft
   :date-released: 2024-12-02
   :priority: High
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Non-Functional
   :safety-asil:
   :references:
   :verification-and-validation:

   The system must be fault-tolerant, ensuring continuous operation even in the presence of errors in USART communication (e.g., by re-initializing or retrying on failure).

.. req:: Documentation
   :id: REQ_INT3_17310281820895
   :status: Draft
   :date-released: 2024-12-02
   :priority: Medium
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Non-Functional
   :safety-asil:
   :references:
   :verification-and-validation:

   The system must include comprehensive documentation covering the setup, configuration, and troubleshooting of USART communication, aiding users in managing and configuring the system.

	
